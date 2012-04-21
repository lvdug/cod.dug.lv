<?php
/**
 * @file
 * cod_session.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function cod_session_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu:program
  $menu_links['main-menu:program'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'program',
    'router_path' => 'program',
    'link_title' => 'Session schedule',
    'options' => array(),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '1',
    'expanded' => '0',
    'weight' => '0',
  );
  // Exported menu link: main-menu:program/sessions
  $menu_links['main-menu:program/sessions'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'program/sessions',
    'router_path' => 'program/sessions',
    'link_title' => 'Sessions',
    'options' => array(),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
    'parent_path' => 'program',
  );
  // Exported menu link: menu-menu-quick-links:program/session-schedule/your-schedule
  $menu_links['menu-menu-quick-links:program/session-schedule/your-schedule'] = array(
    'menu_name' => 'menu-menu-quick-links',
    'link_path' => 'program/session-schedule/your-schedule',
    'router_path' => 'program/session-schedule/your-schedule',
    'link_title' => 'Your schedule',
    'options' => array(
      'attributes' => array(
        'title' => 'Your personal conference schedule',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Session schedule');
  t('Sessions');
  t('Your schedule');


  return $menu_links;
}
