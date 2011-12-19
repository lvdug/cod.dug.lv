<?php
/**
 * @file
 * cod_session.features.user_permission.inc
 */

/**
 * Implementation of hook_user_default_permissions().
 */
function cod_session_user_default_permissions() {
  $permissions = array();

  // Exported permission: edit field_accepted
  $permissions['edit field_accepted'] = array(
    'name' => 'edit field_accepted',
    'roles' => array(
      0 => 'session organizer',
      1 => 'site administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit field_experience
  $permissions['edit field_experience'] = array(
    'name' => 'edit field_experience',
    'roles' => array(),
  );

  // Exported permission: edit field_session_room
  $permissions['edit field_session_room'] = array(
    'name' => 'edit field_session_room',
    'roles' => array(),
  );

  // Exported permission: edit field_session_slot
  $permissions['edit field_session_slot'] = array(
    'name' => 'edit field_session_slot',
    'roles' => array(),
  );

  // Exported permission: edit field_slides
  $permissions['edit field_slides'] = array(
    'name' => 'edit field_slides',
    'roles' => array(),
  );

  // Exported permission: edit field_slot_datetime
  $permissions['edit field_slot_datetime'] = array(
    'name' => 'edit field_slot_datetime',
    'roles' => array(
      0 => 'session organizer',
      1 => 'site administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit field_speakers
  $permissions['edit field_speakers'] = array(
    'name' => 'edit field_speakers',
    'roles' => array(
      0 => 'session organizer',
      1 => 'site administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit field_track
  $permissions['edit field_track'] = array(
    'name' => 'edit field_track',
    'roles' => array(
      0 => 'session organizer',
      1 => 'site administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view field_accepted
  $permissions['view field_accepted'] = array(
    'name' => 'view field_accepted',
    'roles' => array(
      0 => 'session organizer',
      1 => 'site administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view field_experience
  $permissions['view field_experience'] = array(
    'name' => 'view field_experience',
    'roles' => array(),
  );

  // Exported permission: view field_session_room
  $permissions['view field_session_room'] = array(
    'name' => 'view field_session_room',
    'roles' => array(
      0 => 'session organizer',
      1 => 'site administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view field_session_slot
  $permissions['view field_session_slot'] = array(
    'name' => 'view field_session_slot',
    'roles' => array(
      0 => 'session organizer',
      1 => 'site administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view field_slides
  $permissions['view field_slides'] = array(
    'name' => 'view field_slides',
    'roles' => array(),
  );

  // Exported permission: view field_slot_datetime
  $permissions['view field_slot_datetime'] = array(
    'name' => 'view field_slot_datetime',
    'roles' => array(
      0 => 'session organizer',
      1 => 'site administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view field_speakers
  $permissions['view field_speakers'] = array(
    'name' => 'view field_speakers',
    'roles' => array(),
  );

  // Exported permission: view field_track
  $permissions['view field_track'] = array(
    'name' => 'view field_track',
    'roles' => array(
      0 => 'session organizer',
      1 => 'site administrator',
    ),
    'module' => 'field_permissions',
  );

  return $permissions;
}
