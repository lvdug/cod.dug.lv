<?php
/**
 * @file
 * uuid_services_example.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function uuid_services_example_user_default_permissions() {
  $permissions = array();

  // Exported permission: update uuid entity resources
  $permissions['update uuid entity resources'] = array(
    'name' => 'update uuid entity resources',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'uuid_services',
  );

  return $permissions;
}
