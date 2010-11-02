<?php
/**
* Return an array of the modules to be enabled when this profile is installed.
*
* @return
*  An array of modules to be enabled.
*/
function cod_profile_modules() {

  return array(
    // Enable required core modules first.
    'block',
    'filter',
    'node',
    'system',
    'user',
    'dblog',
    // Enable optional core modules next.
    'comment',
    'help',
    'menu',
    'taxonomy',
    'path',
    'profile',
    // Contrib:
    'checkbox_validate',
    'admin',
    'pathauto',
    'globalredirect',
    'path_redirect',
    'comment_notify',
    'ctools',
    'context',
    'strongarm',
    'token',
    'content',
    'content_permissions',
    'fieldgroup',
    'number',
    'optionwidgets',
    'text',
    'filefield',
    'imagefield',
    'nodereference',
    'userreference',
    'link',
    'auto_nodetitle',
    'imageapi',
    'imageapi_gd',
    'imagecache',
    'imagecache_ui',
    'jquery_ui',
    'date_api',
    'date',
    'date_popup',
    'date_tools',
    'date_timezone',
    'views',
    'views_ui',
    'signup',
    'uc_cart',
    'ca',
    'uc_order',
    'uc_store',
    'uc_payment',
    'uc_product',
    'uc_signup',
    'flag',
    'features',
    'diff',
    'cod_session',
    'cod_events',
    'cod_attendees',
    'cod_front_page',
    'cod_news',
    'cod_sponsors',
  );
}

/**
* Return a description of the profile for the initial installation screen.
*
* @return
*   An array with keys 'name' and 'description' describing this profile.
*/
function cod_profile_details() {
  return array(
    'name' => 'Conference Organizing Distribution',
    'description' => 'This software will help you organize a conference-style event.',
  );
}


/**
* Perform any final installation tasks for this profile.
*
* @return
*   An optional HTML string to display to the user on the final installation
*   screen.
*/
function cod_profile_final() {
}

/**
 * Implements hook_form_alter().
 * Set COD as the default profile.
 * (copied from Atrium: We use system_form_form_id_alter, otherwise we cannot alter forms.)
 */
function system_form_install_select_profile_form_alter(&$form, $form_state) {
  foreach ($form['profile'] as $key => $element) {
    $form['profile'][$key]['#value'] = 'cod';
  }
}