<?php

function dclv2012_settings($saved_settings, $subtheme_defaults = array()) {

  // Get the default values from the .info file.
  $defaults = dclv2012_theme_get_default_settings('dclv2012');

  // Merge the saved variables and their default values.
  $settings = array_merge($defaults, $saved_settings);

  /*
   * Create the form using Forms API
   */

  $form['dclv2012_zen_tabs'] = array(
    '#type'          => 'checkbox',
    '#title'         => t('Use Zen Tabs'),
    '#default_value' => $settings['dclv2012_zen_tabs'],
    '#description'   => t('Replace the default tabs by the Zen Tabs.'),
    '#prefix'        => '<strong>' . t('Zen Tabs:') . '</strong>',
  );

  $form['dclv2012_breadcrumb'] = array(
    '#type'          => 'fieldset',
    '#title'         => t('Breadcrumb settings'),
    '#attributes'    => array('id' => 'dclv2012-breadcrumb'),
  );
  $form['dclv2012_breadcrumb']['dclv2012_breadcrumb'] = array(
    '#type'          => 'select',
    '#title'         => t('Display breadcrumb'),
    '#default_value' => $settings['dclv2012_breadcrumb'],
    '#options'       => array(
                          'yes'   => t('Yes'),
                          'admin' => t('Only in admin section'),
                          'no'    => t('No'),
                        ),
  );
  $form['dclv2012_breadcrumb']['dclv2012_breadcrumb_separator'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Breadcrumb separator'),
    '#description'   => t('Text only. Don’t forget to include spaces.'),
    '#default_value' => $settings['dclv2012_breadcrumb_separator'],
    '#size'          => 5,
    '#maxlength'     => 10,
    '#prefix'        => '<div id="div-dclv2012-breadcrumb-collapse">', // jquery hook to show/hide optional widgets
  );
  $form['dclv2012_breadcrumb']['dclv2012_breadcrumb_home'] = array(
    '#type'          => 'checkbox',
    '#title'         => t('Show home page link in breadcrumb'),
    '#default_value' => $settings['dclv2012_breadcrumb_home'],
  );
  $form['dclv2012_breadcrumb']['dclv2012_breadcrumb_trailing'] = array(
    '#type'          => 'checkbox',
    '#title'         => t('Append a separator to the end of the breadcrumb'),
    '#default_value' => $settings['dclv2012_breadcrumb_trailing'],
    '#description'   => t('Useful when the breadcrumb is placed just before the title.'),
  );
  $form['dclv2012_breadcrumb']['dclv2012_breadcrumb_title'] = array(
    '#type'          => 'checkbox',
    '#title'         => t('Append the content title to the end of the breadcrumb'),
    '#default_value' => $settings['dclv2012_breadcrumb_title'],
    '#description'   => t('Useful when the breadcrumb is not placed just before the title.'),
    '#suffix'        => '</div>', // #div-zen-breadcrumb
  );

  $form['dclv2012_wireframe'] = array(
    '#type'          => 'checkbox',
    '#title'         => t('Display borders around main layout elements'),
    '#default_value' => $settings['dclv2012_wireframe'],
    '#description'   => t('<a href="!link">Wireframes</a> are useful when prototyping a website.', array('!link' => 'http://www.boxesandarrows.com/view/html_wireframes_and_prototypes_all_gain_and_no_pain')),
    '#prefix'        => '<strong>' . t('Wireframes:') . '</strong>',
  );

  $form['dclv2012_block_editing'] = array(
    '#type'          => 'checkbox',
    '#title'         => t('Show block editing on hover'),
    '#description'   => t('When hovering over a block, privileged users will see block editing links.'),
    '#default_value' => $settings['dclv2012_block_editing'],
    '#prefix'        => '<strong>' . t('Block Edit Links:') . '</strong>',
  );

  $form['themedev']['dclv2012_rebuild_registry'] = array(
    '#type'          => 'checkbox',
    '#title'         => t('Rebuild theme registry on every page.'),
    '#default_value' => $settings['dclv2012_rebuild_registry'],
    '#description'   => t('During theme development, it can be very useful to continuously <a href="!link">rebuild the theme registry</a>. WARNING: this is a huge performance penalty and must be turned off on production websites.', array('!link' => 'http://drupal.org/node/173880#theme-registry')),
    '#prefix'        => '<div id="div-dclv2012-registry"><strong>' . t('Theme registry:') . '</strong>',
    '#suffix'        => '</div>',
  );

  // Return the form
  return $form;
}

/**
 * Implementation of hook_theme().
 */
function dclv2012_theme(&$existing, $type, $theme, $path) {
  // Each theme has two possible preprocess functions that can act on a hook.
  // This function applies to every hook.
  $functions[0] = $theme . '_preprocess';
  // Inspect the preprocess functions for every hook in the theme registry.
  // @TODO: When PHP 5 becomes required (Basic 7.x), use the following faster
  // implementation: foreach ($existing AS $hook => &$value) {}
  foreach (array_keys($existing) AS $hook) {
    // Each theme has two possible preprocess functions that can act on a hook.
    // This function only applies to this hook.
    $functions[1] = $theme . '_preprocess_' . $hook;
    foreach ($functions AS $key => $function) {
      // Add any functions that are not already in the registry.
      if (function_exists($function) && !in_array($function, $existing[$hook]['preprocess functions'])) {
        // We add the preprocess function to the end of the existing list.
        $existing[$hook]['preprocess functions'][] = $function;
      }
    }
  }

  // Since we are rebuilding the theme registry and the theme settings' default
  // values may have changed, make sure they are saved in the database properly.
  dclv2012_theme_get_default_settings($theme);

  // If we are auto-rebuilding the theme registry, warn about feature.
  if (theme_get_setting('dclv2012_rebuild_registry')) {
    drupal_set_message(t('The theme registry has been rebuilt. <a href="!link">Turn off</a> this feature on production websites.', array('!link' => base_path() . 'admin/build/themes/settings/' . $GLOBALS['theme'])), 'warning');
  }

  // Since we modify the $existing cache directly, return nothing.
  return array();
}

function dclv2012_theme_get_default_settings($theme) {
  $themes = list_themes();

  // Get the default values from the .info file.
  $defaults = !empty($themes[$theme]->info['settings']) ? $themes[$theme]->info['settings'] : array();

  if (!empty($defaults)) {
    // Get the theme settings saved in the database.
    $settings = theme_get_settings($theme);
    // Don't save the toggle_node_info_ variables.
    if (module_exists('node')) {
      foreach (node_get_types() as $type => $name) {
        unset($settings['toggle_node_info_' . $type]);
      }
    }
    // Save default theme settings.
    variable_set(
      str_replace('/', '_', 'theme_' . $theme . '_settings'),
      array_merge($defaults, $settings)
    );
    // If the active theme has been loaded, force refresh of Drupal internals.
    if (!empty($GLOBALS['theme_key'])) {
      theme_get_setting('', TRUE);
    }
  }

  // Return the default settings.
  return $defaults;
}
