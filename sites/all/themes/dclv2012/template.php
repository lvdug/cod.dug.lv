<?php
    
// Auto-rebuild the theme registry during theme development.
if (theme_get_setting('dclv2012_rebuild_registry')) {
  drupal_rebuild_theme_registry();
}

// Add Zen Tabs styles
if (theme_get_setting('dclv2012_zen_tabs')) {
  drupal_add_css( drupal_get_path('theme', 'dclv2012') .'/css/tabs.css', 'theme', 'screen');
}

/**
 *	This function creates the body classes that are relative to each page
 *
 *	@param $vars
 *	  A sequential array of variables to pass to the theme template.
 *	@param $hook
 *	  The name of the theme function being called ("page" in this case.)
 */

function dclv2012_preprocess_page(&$vars, $hook) {

  // Don't display empty help from node_help().
  if ($vars['help'] == "<div class=\"help\"><p></p>\n</div>") {
    $vars['help'] = '';
  }

  // Classes for body element. Allows advanced theming based on context
  // (home page, node of certain type, etc.)
  $body_classes = array($vars['body_classes']);
  if (user_access('administer blocks')) {
	  $body_classes[] = 'admin';
	}
	if (theme_get_setting('dclv2012_wireframe')) {
    $body_classes[] = 'with-wireframes'; // Optionally add the wireframes style.
  }
  if (!empty($vars['primary_links']) or !empty($vars['secondary_links'])) {
    $body_classes[] = 'with-navigation';
  }
  if (!empty($vars['secondary_links'])) {
    $body_classes[] = 'with-secondary';
  }
  if (module_exists('taxonomy') && $vars['node']->nid) {
    foreach (taxonomy_node_get_terms($vars['node']) as $term) {
    $body_classes[] = 'tax-' . eregi_replace('[^a-z0-9]', '-', $term->name);
    }
  }
  if (!$vars['is_front']) {
    // Add unique classes for each page and website section
    $path = drupal_get_path_alias($_GET['q']);
    list($section, ) = explode('/', $path, 2);
    $body_classes[] = dclv2012_id_safe('page-'. $path);
    $body_classes[] = dclv2012_id_safe('section-'. $section);

    if (arg(0) == 'node') {
      if (arg(1) == 'add') {
        if ($section == 'node') {
          array_pop($body_classes); // Remove 'section-node'
        }
        $body_classes[] = 'section-node-add'; // Add 'section-node-add'
      }
      elseif (is_numeric(arg(1)) && (arg(2) == 'edit' || arg(2) == 'delete')) {
        if ($section == 'node') {
          array_pop($body_classes); // Remove 'section-node'
        }
        $body_classes[] = 'section-node-'. arg(2); // Add 'section-node-edit' or 'section-node-delete'
      }
    }
  }
  /*// Check what the user's browser is and add it as a body class
    // DEACTIVATED - Only works if page cache is deactivated
    $user_agent = $_SERVER['HTTP_USER_AGENT'];
    if($user_agent) {
      if (strpos($user_agent, 'MSIE')) {
        $body_classes[] = 'browser-ie';
      } else if (strpos($user_agent, 'MSIE 6.0')) {
        $body_classes[] = 'browser-ie6';
      } else if (strpos($user_agent, 'MSIE 7.0')) {
        $body_classes[] = 'browser-ie7';
      } else if (strpos($user_agent, 'MSIE 8.0')) {
        $body_classes[] = 'browser-ie8'; 
      } else if (strpos($user_agent, 'Firefox/2')) {
        $body_classes[] = 'browser-firefox2';
      } else if (strpos($user_agent, 'Firefox/3')) {
        $body_classes[] = 'browser-firefox3';
      }else if (strpos($user_agent, 'Safari')) {
        $body_classes[] = 'browser-safari';
      } else if (strpos($user_agent, 'Opera')) {
        $body_classes[] = 'browser-opera';
      }
    }
  
  /** 
   * Add template suggestions based on content type
   * You can use a different page template depending on the
   * content type or the node ID
   * For example, if you wish to have a different page template
   * for the story content type, just create a page template called
   * page-type-story.tpl.php
   * For a specific node, use the node ID in the name of the page template
   * like this : page-node-22.tpl.php (if the node ID is 22)
   */
  
  if ($vars['node']->type != "") {
      $vars['template_files'][] = "page-type-" . $vars['node']->type;
    }
  if ($vars['node']->nid != "") {
      $vars['template_files'][] = "page-node-" . $vars['node']->nid;
    }
  $vars['body_classes'] = implode(' ', $body_classes); // Concatenate with spaces
}

/**
 * This function creates the NODES classes, like 'node-unpublished' for nodes
 * that are not published, or 'node-mine' for node posted by the connected user...
 *
 * @param $vars
 *  A sequential array of variables to pass to the theme template.
 * @param $hook
 *  The name of the theme function being called ("node" in this case.)
 */

function dclv2012_preprocess_node(&$vars, $hook) {
  // Special classes for nodes
  $classes = array('node');
  if ($vars['sticky']) {
    $classes[] = 'sticky';
  }
  // support for Skinr Module
  if (module_exists('skinr')) {
    $classes[] = $vars['skinr'];
  }
  if (!$vars['status']) {
    $classes[] = 'node-unpublished';
    $vars['unpublished'] = TRUE;
  }
  else {
    $vars['unpublished'] = FALSE;
  }
  if ($vars['uid'] && $vars['uid'] == $GLOBALS['user']->uid) {
    $classes[] = 'node-mine'; // Node is authored by current user.
  }
  if ($vars['teaser']) {
    $classes[] = 'node-teaser'; // Node is displayed as teaser.
  }
  $classes[] = 'clearfix';
  
  // Class for node type: "node-type-page", "node-type-story", "node-type-my-custom-type", etc.
  $classes[] = dclv2012_id_safe('node-type-' . $vars['type']);
  $vars['classes'] = implode(' ', $classes); // Concatenate with spaces
}

function dclv2012_preprocess_comment_wrapper(&$vars) {
  $classes = array();
  $classes[] = 'comment-wrapper';
  
  // Provide skinr support.
  if (module_exists('skinr')) {
    $classes[] = $vars['skinr'];
  }
  $vars['classes'] = implode(' ', $classes);
}


/**
 * This function create the EDIT LINKS for blocks and menus blocks.
 * When overing a block (except in IE6), some links appear to edit
 * or configure the block. You can then edit the block, and once you are
 * done, brought back to the first page.
 *
 * @param $vars
 *  A sequential array of variables to pass to the theme template.
 * @param $hook
 *  The name of the theme function being called ("block" in this case.)
 */ 

function dclv2012_preprocess_block(&$vars, $hook) {
  $block = $vars['block'];

  // special block classes
  $classes = array('block');
  $classes[] = dclv2012_id_safe('block-' . $vars['block']->module);
  $classes[] = dclv2012_id_safe('block-' . $vars['block']->region);
  $classes[] = dclv2012_id_safe('block-id-' . $vars['block']->bid);
  $classes[] = 'clearfix';
  
  // support for Skinr Module
  if (module_exists('skinr')) {
    $classes[] = $vars['skinr'];
  }
  
  $vars['block_classes'] = implode(' ', $classes); // Concatenate with spaces

  if (theme_get_setting('dclv2012_block_editing') && user_access('administer blocks')) {
    // Display 'edit block' for custom blocks.
    if ($block->module == 'block') {
      $edit_links[] = l('<span>' . t('edit block') . '</span>', 'admin/build/block/configure/' . $block->module . '/' . $block->delta,
        array(
          'attributes' => array(
            'title' => t('edit the content of this block'),
            'class' => 'block-edit',
          ),
          'query' => drupal_get_destination(),
          'html' => TRUE,
        )
      );
    }
    // Display 'configure' for other blocks.
    else {
      $edit_links[] = l('<span>' . t('configure') . '</span>', 'admin/build/block/configure/' . $block->module . '/' . $block->delta,
        array(
          'attributes' => array(
            'title' => t('configure this block'),
            'class' => 'block-config',
          ),
          'query' => drupal_get_destination(),
          'html' => TRUE,
        )
      );
    }
    // Display 'edit menu' for Menu blocks.
    if (($block->module == 'menu' || ($block->module == 'user' && $block->delta == 1)) && user_access('administer menu')) {
      $menu_name = ($block->module == 'user') ? 'navigation' : $block->delta;
      $edit_links[] = l('<span>' . t('edit menu') . '</span>', 'admin/build/menu-customize/' . $menu_name,
        array(
          'attributes' => array(
            'title' => t('edit the menu that defines this block'),
            'class' => 'block-edit-menu',
          ),
          'query' => drupal_get_destination(),
          'html' => TRUE,
        )
      );
    }
    // Display 'edit menu' for Menu block blocks.
    elseif ($block->module == 'menu_block' && user_access('administer menu')) {
      list($menu_name, ) = split(':', variable_get("menu_block_{$block->delta}_parent", 'navigation:0'));
      $edit_links[] = l('<span>' . t('edit menu') . '</span>', 'admin/build/menu-customize/' . $menu_name,
        array(
          'attributes' => array(
            'title' => t('edit the menu that defines this block'),
            'class' => 'block-edit-menu',
          ),
          'query' => drupal_get_destination(),
          'html' => TRUE,
        )
      );
    }
    $vars['edit_links_array'] = $edit_links;
    $vars['edit_links'] = '<div class="edit">' . implode(' ', $edit_links) . '</div>';
  }

  // Add first/last block classes
  $first_last = "";
  // If block id (count) is 1, it's first in region.
  if ($vars['block_id'] == '1') {
    $first_last = " first";
    $vars['block_classes'] .= $first_last;
  }
  // Count amount of blocks about to be rendered in that region.
  $block_count = count(block_list($vars['block']->region));
  if ($vars['block_id'] == $block_count) {
    $first_last = " last";
    $vars['block_classes'] .= $first_last;
  }
}

/**
 * Override or insert PHPTemplate variables into the block templates.
 *
 * @param $vars
 *  An array of variables to pass to the theme template.
 * @param $hook
 *  The name of the template being rendered ("comment" in this case.)
 */

function dclv2012_preprocess_comment(&$vars, $hook) {
  // Add an "unpublished" flag.
  $vars['unpublished'] = ($vars['comment']->status == COMMENT_NOT_PUBLISHED);

  // If comment subjects are disabled, don't display them.
  if (variable_get('comment_subject_field_' . $vars['node']->type, 1) == 0) {
    $vars['title'] = '';
  }

  // Special classes for comments.
  $classes = array('comment');
  if ($vars['comment']->new) {
    $classes[] = 'comment-new';
  }
  $classes[] = $vars['status'];
  $classes[] = $vars['zebra'];
  if ($vars['id'] == 1) {
    $classes[] = 'first';
  }
  if ($vars['id'] == $vars['node']->comment_count) {
    $classes[] = 'last';
  }
  if ($vars['comment']->uid == 0) {
    // Comment is by an anonymous user.
    $classes[] = 'comment-by-anon';
  }
  else {
    if ($vars['comment']->uid == $vars['node']->uid) {
      // Comment is by the node author.
      $classes[] = 'comment-by-author';
    }
    if ($vars['comment']->uid == $GLOBALS['user']->uid) {
      // Comment was posted by current user.
      $classes[] = 'comment-mine';
    }
  }
  $vars['classes'] = implode(' ', $classes);
}

/**
 * Customize the PRIMARY and SECONDARY LINKS, to allow the admin tabs to work on all browsers
 * An implementation of theme_menu_item_link()
 *
 * @param $link
 * 	array The menu item to render.
 * @return
 * 	string The rendered menu item.
 */ 	

function dclv2012_menu_item_link($link) {
  if (empty($link['localized_options'])) {
    $link['localized_options'] = array();
  }

  // If an item is a LOCAL TASK, render it as a tab
  if ($link['type'] & MENU_IS_LOCAL_TASK) {
    $link['title'] = '<span class="tab">' . check_plain($link['title']) . '</span>';
    $link['localized_options']['html'] = TRUE;
  }

  return l($link['title'], $link['href'], $link['localized_options']);
}


/**
 * Duplicate of theme_menu_local_tasks() but adds clear-block to tabs.
 */

function dclv2012_menu_local_tasks() {
  $output = '';
  if ($primary = menu_primary_local_tasks()) {
    if(menu_secondary_local_tasks()) {
      $output .= '<ul class="tabs primary with-secondary clearfix">' . $primary . '</ul>';
    }
    else {
      $output .= '<ul class="tabs primary clearfix">' . $primary . '</ul>';
    }
  }
  if ($secondary = menu_secondary_local_tasks()) {
    $output .= '<ul class="tabs secondary clearfix">' . $secondary . '</ul>';
  }
  return $output;
}

/**
 * Add custom classes to menu item
 */	
	
function dclv2012_menu_item($link, $has_children, $menu = '', $in_active_trail = FALSE, $extra_class = NULL) {
  $class = ($menu ? 'expanded' : ($has_children ? 'collapsed' : 'leaf'));
  if (!empty($extra_class)) {
    $class .= ' '. $extra_class;
  }
  if ($in_active_trail) {
    $class .= ' active-trail';
  }
  // New line added to get unique classes for each menu item
  $css_class = dclv2012_id_safe(str_replace(' ', '_', strip_tags($link)));
  return '<li class="'. $class . ' ' . $css_class . '">' . $link . $menu ."</li>\n";
}

/**
 *	Converts a string to a suitable html ID attribute.
 *	
 *	 http://www.w3.org/TR/html4/struct/global.html#h-7.5.2 specifies what makes a
 *	 valid ID attribute in HTML. This function:
 *	
 *	- Ensure an ID starts with an alpha character by optionally adding an 'n'.
 *	- Replaces any character except A-Z, numbers, and underscores with dashes.
 *	- Converts entire string to lowercase.
 *	
 *	@param $string
 *	 The string
 *	@return
 *	 The converted string
 */	

function dclv2012_id_safe($string) {
  // Replace with dashes anything that isn't A-Z, numbers, dashes, or underscores.
  $string = strtolower(preg_replace('/[^a-zA-Z0-9_-]+/', '-', $string));
  // If the first character is not a-z, add 'n' in front.
  if (!ctype_lower($string{0})) { // Don't use ctype_alpha since its locale aware.
    $string = 'id'. $string;
  }
  return $string;
}

/**
 * Return a themed breadcrumb trail.
 *
 * @param $breadcrumb
 *  An array containing the breadcrumb links.
 * @return
 *  A string containing the breadcrumb output.
 */
function dclv2012_breadcrumb($breadcrumb) {
  // Determine if we are to display the breadcrumb.
  $show_breadcrumb = theme_get_setting('dclv2012_breadcrumb');
  if ($show_breadcrumb == 'yes' || $show_breadcrumb == 'admin' && arg(0) == 'admin') {

    // Optionally get rid of the homepage link.
    $show_breadcrumb_home = theme_get_setting('dclv2012_breadcrumb_home');
    if (!$show_breadcrumb_home) {
      array_shift($breadcrumb);
    }

    // Return the breadcrumb with separators.
    if (!empty($breadcrumb)) {
      $breadcrumb_separator = theme_get_setting('dclv2012_breadcrumb_separator');
      $trailing_separator = $title = '';
      if (theme_get_setting('dclv2012_breadcrumb_title')) {
        if ($title = drupal_get_title()) {
          $trailing_separator = $breadcrumb_separator;
        }
      }
      elseif (theme_get_setting('dclv2012_breadcrumb_trailing')) {
        $trailing_separator = $breadcrumb_separator;
      }
      return '<div class="breadcrumb">' . implode($breadcrumb_separator, $breadcrumb) . "$trailing_separator$title</div>";
    }
  }
  // Otherwise, return an empty string.
  return '';
}
