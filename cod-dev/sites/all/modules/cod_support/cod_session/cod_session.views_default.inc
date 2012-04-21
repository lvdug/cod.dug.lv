<?php
/**
 * @file
 * cod_session.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function cod_session_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'cod_schedule';
  $view->description = 'Session Schedule';
  $view->tag = 'cod session';
  $view->base_table = 'node';
  $view->human_name = '';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Schedule (Access Restricted)';
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    4 => '4',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'cod_session_schedule';
  $handler->display->display_options['style_options']['schedule_interactive'] = '0';
  $handler->display->display_options['style_options']['schedule_days'] = array(
    'Sunday February, 26 2012' => 0,
  );
  $handler->display->display_options['style_options']['interactive_type'] = 'session';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'The schedule is empty';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'Please create one or more rooms and time slots, and assign a session or schedule item to them. For help with scheduling, please see the <a href="http://drupal.org/documentation/build/cod/">COD Documentation</a>.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  /* Relationship: Flags: session_schedule */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['label'] = 'flag: session_schedule';
  $handler->display->display_options['relationships']['flag_content_rel']['required'] = 0;
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'session_schedule';
  /* Field: Content: Track */
  $handler->display->display_options['fields']['field_track']['id'] = 'field_track';
  $handler->display->display_options['fields']['field_track']['table'] = 'field_data_field_track';
  $handler->display->display_options['fields']['field_track']['field'] = 'field_track';
  $handler->display->display_options['fields']['field_track']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_track']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_track']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_track']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_track']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_track']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_track']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_track']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_track']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_track']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_track']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_track']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_track']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_track']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_track']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_track']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_track']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_track']['field_api_classes'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<strong>[title]</strong>';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Speaker(s) */
  $handler->display->display_options['fields']['field_speakers']['id'] = 'field_speakers';
  $handler->display->display_options['fields']['field_speakers']['table'] = 'field_data_field_speakers';
  $handler->display->display_options['fields']['field_speakers']['field'] = 'field_speakers';
  $handler->display->display_options['fields']['field_speakers']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_speakers']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_speakers']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_speakers']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_speakers']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_speakers']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_speakers']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_speakers']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_speakers']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_speakers']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_speakers']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_speakers']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_speakers']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_speakers']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_speakers']['hide_empty'] = 1;
  $handler->display->display_options['fields']['field_speakers']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_speakers']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_speakers']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_speakers']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_speakers']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_speakers']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_speakers']['field_api_classes'] = 0;
  /* Field: Content: Experience level */
  $handler->display->display_options['fields']['field_experience']['id'] = 'field_experience';
  $handler->display->display_options['fields']['field_experience']['table'] = 'field_data_field_experience';
  $handler->display->display_options['fields']['field_experience']['field'] = 'field_experience';
  $handler->display->display_options['fields']['field_experience']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_experience']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_experience']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_experience']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_experience']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_experience']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_experience']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_experience']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_experience']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_experience']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_experience']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_experience']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_experience']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_experience']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_experience']['hide_empty'] = 1;
  $handler->display->display_options['fields']['field_experience']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_experience']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_experience']['field_api_classes'] = 0;
  /* Field: Flags: Flag link */
  $handler->display->display_options['fields']['ops']['id'] = 'ops';
  $handler->display->display_options['fields']['ops']['table'] = 'flag_content';
  $handler->display->display_options['fields']['ops']['field'] = 'ops';
  $handler->display->display_options['fields']['ops']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['ops']['label'] = '';
  $handler->display->display_options['fields']['ops']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['external'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['ops']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['ops']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['html'] = 0;
  $handler->display->display_options['fields']['ops']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['ops']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['ops']['hide_empty'] = 0;
  $handler->display->display_options['fields']['ops']['empty_zero'] = 0;
  $handler->display->display_options['fields']['ops']['hide_alter_empty'] = 1;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'schedule_item' => 'schedule_item',
    'session' => 'session',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Status (field_accepted) */
  $handler->display->display_options['filters']['field_accepted_value']['id'] = 'field_accepted_value';
  $handler->display->display_options['filters']['field_accepted_value']['table'] = 'field_data_field_accepted';
  $handler->display->display_options['filters']['field_accepted_value']['field'] = 'field_accepted_value';
  $handler->display->display_options['filters']['field_accepted_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_accepted_value']['group'] = 1;
  /* Filter criterion: Content: Room (field_session_room) */
  $handler->display->display_options['filters']['field_session_room_nid']['id'] = 'field_session_room_nid';
  $handler->display->display_options['filters']['field_session_room_nid']['table'] = 'field_data_field_session_room';
  $handler->display->display_options['filters']['field_session_room_nid']['field'] = 'field_session_room_nid';
  $handler->display->display_options['filters']['field_session_room_nid']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_session_room_nid']['group'] = 1;
  /* Filter criterion: Content: Time slot (field_session_slot) */
  $handler->display->display_options['filters']['field_session_slot_nid']['id'] = 'field_session_slot_nid';
  $handler->display->display_options['filters']['field_session_slot_nid']['table'] = 'field_data_field_session_slot';
  $handler->display->display_options['filters']['field_session_slot_nid']['field'] = 'field_session_slot_nid';
  $handler->display->display_options['filters']['field_session_slot_nid']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_session_slot_nid']['group'] = 1;

  /* Display: Schedule */
  $handler = $view->new_display('page', 'Schedule', 'page_1');
  $handler->display->display_options['path'] = 'program/session-schedule';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'Session Schedule';
  $handler->display->display_options['menu']['weight'] = '-50';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Session schedule';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'main-menu';

  /* Display: Primary Sessions Block */
  $handler = $view->new_display('block', 'Primary Sessions Block', 'block_1');
  $handler->display->display_options['block_description'] = 'Primary Sessions';

  /* Display: Your schedule */
  $handler = $view->new_display('page', 'Your schedule', 'page_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Your schedule';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'Your schedule is empty';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'You can add sessions to your personal schedule from the <a href="/program/session-schedule">main schedule.</a>';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'schedule_item' => 'schedule_item',
    'session' => 'session',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Status (field_accepted) */
  $handler->display->display_options['filters']['field_accepted_value']['id'] = 'field_accepted_value';
  $handler->display->display_options['filters']['field_accepted_value']['table'] = 'field_data_field_accepted';
  $handler->display->display_options['filters']['field_accepted_value']['field'] = 'field_accepted_value';
  $handler->display->display_options['filters']['field_accepted_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_accepted_value']['group'] = 1;
  /* Filter criterion: Content: Room (field_session_room) */
  $handler->display->display_options['filters']['field_session_room_nid']['id'] = 'field_session_room_nid';
  $handler->display->display_options['filters']['field_session_room_nid']['table'] = 'field_data_field_session_room';
  $handler->display->display_options['filters']['field_session_room_nid']['field'] = 'field_session_room_nid';
  $handler->display->display_options['filters']['field_session_room_nid']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_session_room_nid']['group'] = 1;
  /* Filter criterion: Content: Time slot (field_session_slot) */
  $handler->display->display_options['filters']['field_session_slot_nid']['id'] = 'field_session_slot_nid';
  $handler->display->display_options['filters']['field_session_slot_nid']['table'] = 'field_data_field_session_slot';
  $handler->display->display_options['filters']['field_session_slot_nid']['field'] = 'field_session_slot_nid';
  $handler->display->display_options['filters']['field_session_slot_nid']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_session_slot_nid']['group'] = 1;
  /* Filter criterion: Flags: Flagged */
  $handler->display->display_options['filters']['flagged']['id'] = 'flagged';
  $handler->display->display_options['filters']['flagged']['table'] = 'flag_content';
  $handler->display->display_options['filters']['flagged']['field'] = 'flagged';
  $handler->display->display_options['filters']['flagged']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['filters']['flagged']['value'] = '1';
  $handler->display->display_options['filters']['flagged']['group'] = 1;
  $handler->display->display_options['path'] = 'program/session-schedule/your-schedule';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Your schedule';
  $handler->display->display_options['menu']['weight'] = '-49';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['tab_options']['weight'] = '0';
  $export['cod_schedule'] = $view;

  $view = new view;
  $view->name = 'cod_time_slots';
  $view->description = 'List of time slots for COD schedules';
  $view->tag = 'cod session';
  $view->base_table = 'node';
  $view->human_name = '';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Sort criterion: Content: Date and time (field_slot_datetime) */
  $handler->display->display_options['sorts']['field_slot_datetime_value']['id'] = 'field_slot_datetime_value';
  $handler->display->display_options['sorts']['field_slot_datetime_value']['table'] = 'field_data_field_slot_datetime';
  $handler->display->display_options['sorts']['field_slot_datetime_value']['field'] = 'field_slot_datetime_value';
  /* Contextual filter: Content: Date and time (field_slot_datetime) */
  $handler->display->display_options['arguments']['field_slot_datetime_value']['id'] = 'field_slot_datetime_value';
  $handler->display->display_options['arguments']['field_slot_datetime_value']['table'] = 'field_data_field_slot_datetime';
  $handler->display->display_options['arguments']['field_slot_datetime_value']['field'] = 'field_slot_datetime_value';
  $handler->display->display_options['arguments']['field_slot_datetime_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_slot_datetime_value']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_slot_datetime_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_slot_datetime_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_slot_datetime_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_slot_datetime_value']['specify_validation'] = 1;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'time_slot' => 'time_slot',
  );
  $export['cod_time_slots'] = $view;

  $view = new view;
  $view->name = 'schedule_room_list';
  $view->description = 'List of rooms for COD schedules';
  $view->tag = 'cod session';
  $view->base_table = 'node';
  $view->human_name = '';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 0;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['nid']['link_to_node'] = 0;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'room' => 'room',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['filters']['type']['expose']['operator'] = FALSE;
  $export['schedule_room_list'] = $view;

  $view = new view;
  $view->name = 'sessions';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'sessions';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Proposed Sessions';
  $handler->display->display_options['link_display'] = 'page_1';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = '';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_speakers' => 'field_speakers',
    'body' => 'body',
    'field_accepted' => 'field_accepted',
    'field_experience' => 'field_experience',
    'field_track' => 'field_track',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '<br>',
      'empty_column' => 0,
    ),
    'field_speakers' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'body' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_accepted' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_experience' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_track' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 1;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'No sessions...';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'No sessions have been submitted.';
  $handler->display->display_options['empty']['area']['format'] = 'plain_text';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Session';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Speaker(s) */
  $handler->display->display_options['fields']['field_speakers']['id'] = 'field_speakers';
  $handler->display->display_options['fields']['field_speakers']['table'] = 'field_data_field_speakers';
  $handler->display->display_options['fields']['field_speakers']['field'] = 'field_speakers';
  $handler->display->display_options['fields']['field_speakers']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_speakers']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_speakers']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_speakers']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_speakers']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_speakers']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_speakers']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_speakers']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_speakers']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_speakers']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_speakers']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_speakers']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_speakers']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_speakers']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_speakers']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_speakers']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_speakers']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_speakers']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_speakers']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_speakers']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_speakers']['field_api_classes'] = 0;
  /* Field: Content: Description */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['body']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['body']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['body']['alter']['external'] = 0;
  $handler->display->display_options['fields']['body']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['body']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['body']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '200';
  $handler->display->display_options['fields']['body']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['body']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['body']['alter']['trim'] = 1;
  $handler->display->display_options['fields']['body']['alter']['html'] = 0;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['body']['hide_empty'] = 0;
  $handler->display->display_options['fields']['body']['empty_zero'] = 0;
  $handler->display->display_options['fields']['body']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '250',
  );
  $handler->display->display_options['fields']['body']['field_api_classes'] = 0;
  /* Field: Content: Status */
  $handler->display->display_options['fields']['field_accepted']['id'] = 'field_accepted';
  $handler->display->display_options['fields']['field_accepted']['table'] = 'field_data_field_accepted';
  $handler->display->display_options['fields']['field_accepted']['field'] = 'field_accepted';
  $handler->display->display_options['fields']['field_accepted']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_accepted']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_accepted']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_accepted']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_accepted']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_accepted']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_accepted']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_accepted']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_accepted']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_accepted']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_accepted']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_accepted']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_accepted']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_accepted']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_accepted']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_accepted']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_accepted']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_accepted']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_accepted']['field_api_classes'] = 0;
  /* Field: Content: Experience level */
  $handler->display->display_options['fields']['field_experience']['id'] = 'field_experience';
  $handler->display->display_options['fields']['field_experience']['table'] = 'field_data_field_experience';
  $handler->display->display_options['fields']['field_experience']['field'] = 'field_experience';
  $handler->display->display_options['fields']['field_experience']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_experience']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_experience']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_experience']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_experience']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_experience']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_experience']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_experience']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_experience']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_experience']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_experience']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_experience']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_experience']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_experience']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_experience']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_experience']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_experience']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_experience']['field_api_classes'] = 0;
  /* Field: Content: Track */
  $handler->display->display_options['fields']['field_track']['id'] = 'field_track';
  $handler->display->display_options['fields']['field_track']['table'] = 'field_data_field_track';
  $handler->display->display_options['fields']['field_track']['field'] = 'field_track';
  $handler->display->display_options['fields']['field_track']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_track']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_track']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_track']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_track']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_track']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_track']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_track']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_track']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_track']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_track']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_track']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_track']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_track']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_track']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_track']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_track']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_track']['field_api_classes'] = 0;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'session' => 'session',
  );
  /* Filter criterion: Content: Experience level (field_experience) */
  $handler->display->display_options['filters']['field_experience_value']['id'] = 'field_experience_value';
  $handler->display->display_options['filters']['field_experience_value']['table'] = 'field_data_field_experience';
  $handler->display->display_options['filters']['field_experience_value']['field'] = 'field_experience_value';
  $handler->display->display_options['filters']['field_experience_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_experience_value']['expose']['operator_id'] = 'field_experience_value_op';
  $handler->display->display_options['filters']['field_experience_value']['expose']['label'] = 'Experience';
  $handler->display->display_options['filters']['field_experience_value']['expose']['operator'] = 'field_experience_value_op';
  $handler->display->display_options['filters']['field_experience_value']['expose']['identifier'] = 'field_experience_value';
  $handler->display->display_options['filters']['field_experience_value']['expose']['reduce'] = 0;
  /* Filter criterion: Content: Track (field_track) */
  $handler->display->display_options['filters']['field_track_value']['id'] = 'field_track_value';
  $handler->display->display_options['filters']['field_track_value']['table'] = 'field_data_field_track';
  $handler->display->display_options['filters']['field_track_value']['field'] = 'field_track_value';
  $handler->display->display_options['filters']['field_track_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_track_value']['expose']['operator_id'] = 'field_track_value_op';
  $handler->display->display_options['filters']['field_track_value']['expose']['label'] = 'Track';
  $handler->display->display_options['filters']['field_track_value']['expose']['operator'] = 'field_track_value_op';
  $handler->display->display_options['filters']['field_track_value']['expose']['identifier'] = 'field_track_value';
  $handler->display->display_options['filters']['field_track_value']['expose']['reduce'] = 0;
  /* Filter criterion: Search: Search Terms */
  $handler->display->display_options['filters']['keys']['id'] = 'keys';
  $handler->display->display_options['filters']['keys']['table'] = 'search_index';
  $handler->display->display_options['filters']['keys']['field'] = 'keys';
  $handler->display->display_options['filters']['keys']['exposed'] = TRUE;
  $handler->display->display_options['filters']['keys']['expose']['operator_id'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['label'] = 'Filter by keywords';
  $handler->display->display_options['filters']['keys']['expose']['operator'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['identifier'] = 'keys';
  $handler->display->display_options['filters']['keys']['expose']['multiple'] = FALSE;
  /* Filter criterion: Content: Status (field_accepted) */
  $handler->display->display_options['filters']['field_accepted_value']['id'] = 'field_accepted_value';
  $handler->display->display_options['filters']['field_accepted_value']['table'] = 'field_data_field_accepted';
  $handler->display->display_options['filters']['field_accepted_value']['field'] = 'field_accepted_value';
  $handler->display->display_options['filters']['field_accepted_value']['value'] = array(
    1 => '1',
  );

  /* Display: Page: Proposed */
  $handler = $view->new_display('page', 'Page: Proposed', 'page_proposed');
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'session' => 'session',
  );
  $handler->display->display_options['filters']['type']['group'] = 0;
  /* Filter criterion: Content: Experience level (field_experience) */
  $handler->display->display_options['filters']['field_experience_value']['id'] = 'field_experience_value';
  $handler->display->display_options['filters']['field_experience_value']['table'] = 'field_data_field_experience';
  $handler->display->display_options['filters']['field_experience_value']['field'] = 'field_experience_value';
  $handler->display->display_options['filters']['field_experience_value']['group'] = 0;
  $handler->display->display_options['filters']['field_experience_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_experience_value']['expose']['operator_id'] = 'field_experience_value_op';
  $handler->display->display_options['filters']['field_experience_value']['expose']['label'] = 'Experience level';
  $handler->display->display_options['filters']['field_experience_value']['expose']['operator'] = 'field_experience_value_op';
  $handler->display->display_options['filters']['field_experience_value']['expose']['identifier'] = 'field_experience_value';
  $handler->display->display_options['filters']['field_experience_value']['expose']['reduce'] = 0;
  /* Filter criterion: Content: Track (field_track) */
  $handler->display->display_options['filters']['field_track_value']['id'] = 'field_track_value';
  $handler->display->display_options['filters']['field_track_value']['table'] = 'field_data_field_track';
  $handler->display->display_options['filters']['field_track_value']['field'] = 'field_track_value';
  $handler->display->display_options['filters']['field_track_value']['group'] = 0;
  $handler->display->display_options['filters']['field_track_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_track_value']['expose']['operator_id'] = 'field_track_value_op';
  $handler->display->display_options['filters']['field_track_value']['expose']['label'] = 'Track';
  $handler->display->display_options['filters']['field_track_value']['expose']['operator'] = 'field_track_value_op';
  $handler->display->display_options['filters']['field_track_value']['expose']['identifier'] = 'field_track_value';
  $handler->display->display_options['filters']['field_track_value']['expose']['reduce'] = 0;
  /* Filter criterion: Search: Search Terms */
  $handler->display->display_options['filters']['keys']['id'] = 'keys';
  $handler->display->display_options['filters']['keys']['table'] = 'search_index';
  $handler->display->display_options['filters']['keys']['field'] = 'keys';
  $handler->display->display_options['filters']['keys']['group'] = 0;
  $handler->display->display_options['filters']['keys']['exposed'] = TRUE;
  $handler->display->display_options['filters']['keys']['expose']['operator_id'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['label'] = 'Filter by keywords:';
  $handler->display->display_options['filters']['keys']['expose']['operator'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['identifier'] = 'keys';
  $handler->display->display_options['filters']['keys']['expose']['multiple'] = FALSE;
  /* Filter criterion: Content: Status (field_accepted) */
  $handler->display->display_options['filters']['field_accepted_value_1']['id'] = 'field_accepted_value_1';
  $handler->display->display_options['filters']['field_accepted_value_1']['table'] = 'field_data_field_accepted';
  $handler->display->display_options['filters']['field_accepted_value_1']['field'] = 'field_accepted_value';
  $handler->display->display_options['filters']['field_accepted_value_1']['value'] = array(
    0 => '0',
  );
  $handler->display->display_options['filters']['field_accepted_value_1']['group'] = 0;
  $handler->display->display_options['path'] = 'program/sessions/proposed';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Proposed Sessions';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';

  /* Display: Page: Accepted */
  $handler = $view->new_display('page', 'Page: Accepted', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Accepted Sessions';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_speakers' => 'field_speakers',
    'body' => 'body',
    'field_accepted' => 'field_accepted',
    'field_experience' => 'field_experience',
    'field_track' => 'field_track',
  );
  $handler->display->display_options['style_options']['default'] = 'title';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_speakers' => array(
      'align' => '',
      'separator' => '',
    ),
    'body' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_accepted' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_experience' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_track' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 1;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'No sessions...';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'No sessions have been accepted yet.';
  $handler->display->display_options['empty']['area']['format'] = 'plain_text';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['path'] = 'program/sessions/accepted';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'Accepted Sessions';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Sessions';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'main-menu';

  /* Display: Feed: All */
  $handler = $view->new_display('feed', 'Feed: All', 'feed_1');
  $handler->display->display_options['defaults']['link_display'] = FALSE;
  $handler->display->display_options['link_display'] = 'page_proposed';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['row_plugin'] = 'node_rss';
  $handler->display->display_options['row_options']['item_length'] = 'full';
  $handler->display->display_options['row_options']['links'] = 0;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'session' => 'session',
  );
  /* Filter criterion: Content: Experience level (field_experience) */
  $handler->display->display_options['filters']['field_experience_value']['id'] = 'field_experience_value';
  $handler->display->display_options['filters']['field_experience_value']['table'] = 'field_data_field_experience';
  $handler->display->display_options['filters']['field_experience_value']['field'] = 'field_experience_value';
  $handler->display->display_options['filters']['field_experience_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_experience_value']['expose']['operator_id'] = 'field_experience_value_op';
  $handler->display->display_options['filters']['field_experience_value']['expose']['label'] = 'Experience';
  $handler->display->display_options['filters']['field_experience_value']['expose']['operator'] = 'field_experience_value_op';
  $handler->display->display_options['filters']['field_experience_value']['expose']['identifier'] = 'field_experience_value';
  $handler->display->display_options['filters']['field_experience_value']['expose']['reduce'] = 0;
  /* Filter criterion: Content: Track (field_track) */
  $handler->display->display_options['filters']['field_track_value']['id'] = 'field_track_value';
  $handler->display->display_options['filters']['field_track_value']['table'] = 'field_data_field_track';
  $handler->display->display_options['filters']['field_track_value']['field'] = 'field_track_value';
  $handler->display->display_options['filters']['field_track_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_track_value']['expose']['operator_id'] = 'field_track_value_op';
  $handler->display->display_options['filters']['field_track_value']['expose']['label'] = 'Track';
  $handler->display->display_options['filters']['field_track_value']['expose']['operator'] = 'field_track_value_op';
  $handler->display->display_options['filters']['field_track_value']['expose']['identifier'] = 'field_track_value';
  $handler->display->display_options['filters']['field_track_value']['expose']['reduce'] = 0;
  /* Filter criterion: Search: Search Terms */
  $handler->display->display_options['filters']['keys']['id'] = 'keys';
  $handler->display->display_options['filters']['keys']['table'] = 'search_index';
  $handler->display->display_options['filters']['keys']['field'] = 'keys';
  $handler->display->display_options['filters']['keys']['exposed'] = TRUE;
  $handler->display->display_options['filters']['keys']['expose']['operator_id'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['label'] = 'Filter by keywords';
  $handler->display->display_options['filters']['keys']['expose']['operator'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['identifier'] = 'keys';
  $handler->display->display_options['filters']['keys']['expose']['multiple'] = FALSE;
  $handler->display->display_options['path'] = 'program/sessions/proposed/rss';
  $handler->display->display_options['displays'] = array(
    'page_1' => 'page_1',
    'default' => 0,
    'page_proposed' => 0,
  );

  /* Display: Block: Sessions Details */
  $handler = $view->new_display('block', 'Block: Sessions Details', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Sessions Details';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'session-details';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Time slot (field_session_slot) */
  $handler->display->display_options['relationships']['field_session_slot_nid']['id'] = 'field_session_slot_nid';
  $handler->display->display_options['relationships']['field_session_slot_nid']['table'] = 'field_data_field_session_slot';
  $handler->display->display_options['relationships']['field_session_slot_nid']['field'] = 'field_session_slot_nid';
  $handler->display->display_options['relationships']['field_session_slot_nid']['required'] = 0;
  $handler->display->display_options['relationships']['field_session_slot_nid']['delta'] = '-1';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Status */
  $handler->display->display_options['fields']['field_accepted']['id'] = 'field_accepted';
  $handler->display->display_options['fields']['field_accepted']['table'] = 'field_data_field_accepted';
  $handler->display->display_options['fields']['field_accepted']['field'] = 'field_accepted';
  $handler->display->display_options['fields']['field_accepted']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_accepted']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_accepted']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_accepted']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_accepted']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_accepted']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_accepted']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_accepted']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_accepted']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_accepted']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_accepted']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_accepted']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_accepted']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_accepted']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_accepted']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_accepted']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_accepted']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_accepted']['field_api_classes'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Session';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Track */
  $handler->display->display_options['fields']['field_track']['id'] = 'field_track';
  $handler->display->display_options['fields']['field_track']['table'] = 'field_data_field_track';
  $handler->display->display_options['fields']['field_track']['field'] = 'field_track';
  $handler->display->display_options['fields']['field_track']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_track']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_track']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_track']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_track']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_track']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_track']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_track']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_track']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_track']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_track']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_track']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_track']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_track']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_track']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_track']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_track']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_track']['field_api_classes'] = 0;
  /* Field: Content: Room */
  $handler->display->display_options['fields']['field_session_room']['id'] = 'field_session_room';
  $handler->display->display_options['fields']['field_session_room']['table'] = 'field_data_field_session_room';
  $handler->display->display_options['fields']['field_session_room']['field'] = 'field_session_room';
  $handler->display->display_options['fields']['field_session_room']['label'] = 'Room (field_session_room) - delta';
  $handler->display->display_options['fields']['field_session_room']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_session_room']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_session_room']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_session_room']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_session_room']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_session_room']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_session_room']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_session_room']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_session_room']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_session_room']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_session_room']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_session_room']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_session_room']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_session_room']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_session_room']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_session_room']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_session_room']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_session_room']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_session_room']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_session_room']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_session_room']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_session_room']['field_api_classes'] = 0;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = 1;
  $handler->display->display_options['arguments']['nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['nid']['not'] = 0;

  /* Display: Block: Speakers */
  $handler = $view->new_display('block', 'Block: Speakers', 'block_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Speakers';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'session-speakers';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['grouping'] = '';
  $handler->display->display_options['style_options']['columns'] = '1';
  $handler->display->display_options['style_options']['fill_single_line'] = 1;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_speakers' => 'field_speakers',
  );
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Speaker(s) (field_speakers) */
  $handler->display->display_options['relationships']['field_speakers_uid']['id'] = 'field_speakers_uid';
  $handler->display->display_options['relationships']['field_speakers_uid']['table'] = 'field_data_field_speakers';
  $handler->display->display_options['relationships']['field_speakers_uid']['field'] = 'field_speakers_uid';
  $handler->display->display_options['relationships']['field_speakers_uid']['required'] = 0;
  $handler->display->display_options['relationships']['field_speakers_uid']['delta'] = '-1';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: User: Picture */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['relationship'] = 'field_speakers_uid';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['external'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['picture']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['picture']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['html'] = 0;
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['picture']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['picture']['hide_empty'] = 0;
  $handler->display->display_options['fields']['picture']['empty_zero'] = 0;
  $handler->display->display_options['fields']['picture']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['picture']['link_photo_to_profile'] = 0;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name_1']['id'] = 'name_1';
  $handler->display->display_options['fields']['name_1']['table'] = 'users';
  $handler->display->display_options['fields']['name_1']['field'] = 'name';
  $handler->display->display_options['fields']['name_1']['relationship'] = 'field_speakers_uid';
  $handler->display->display_options['fields']['name_1']['label'] = '';
  $handler->display->display_options['fields']['name_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['name_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['name_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name_1']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['name_1']['link_to_user'] = 1;
  $handler->display->display_options['fields']['name_1']['overwrite_anonymous'] = 0;
  $handler->display->display_options['fields']['name_1']['format_username'] = 1;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'field_speakers_uid';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['name']['alter']['text'] = '([name_1])';
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['name']['link_to_user'] = 1;
  $handler->display->display_options['fields']['name']['overwrite_anonymous'] = 0;
  $handler->display->display_options['fields']['name']['format_username'] = 1;
  /* Field: User: Organization */
  $handler->display->display_options['fields']['field_profile_org']['id'] = 'field_profile_org';
  $handler->display->display_options['fields']['field_profile_org']['table'] = 'field_data_field_profile_org';
  $handler->display->display_options['fields']['field_profile_org']['field'] = 'field_profile_org';
  $handler->display->display_options['fields']['field_profile_org']['relationship'] = 'field_speakers_uid';
  $handler->display->display_options['fields']['field_profile_org']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_profile_org']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['field_profile_org']['alter']['path'] = 'organization/[value]';
  $handler->display->display_options['fields']['field_profile_org']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_profile_org']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_profile_org']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_profile_org']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_profile_org']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_profile_org']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_profile_org']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_profile_org']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_profile_org']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_profile_org']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_profile_org']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_profile_org']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_profile_org']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_profile_org']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_profile_org']['hide_alter_empty'] = 1;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: User: Name */
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'users';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  $handler->display->display_options['sorts']['name']['relationship'] = 'field_speakers_uid';
  $handler->display->display_options['sorts']['name']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = 1;
  $handler->display->display_options['arguments']['nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['nid']['not'] = 0;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'session' => 'session',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Status (field_accepted) */
  $handler->display->display_options['filters']['field_accepted_value']['id'] = 'field_accepted_value';
  $handler->display->display_options['filters']['field_accepted_value']['table'] = 'field_data_field_accepted';
  $handler->display->display_options['filters']['field_accepted_value']['field'] = 'field_accepted_value';
  $handler->display->display_options['filters']['field_accepted_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_accepted_value']['group'] = 1;
  $handler->display->display_options['block_description'] = 'Sessions: Speakers';
  $export['sessions'] = $view;

  $view = new view;
  $view->name = 'sessions_admin';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'sessions_admin';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Sessions';
  $handler->display->display_options['css_class'] = 'view-grouped-list sessions-list';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'edit field_accepted';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = 0;
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = 1;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_accepted' => 'field_accepted',
    'field_speakers' => 'field_speakers',
    'field_experience' => 'field_experience',
    'field_track' => 'field_track',
    'edit_node' => 'edit_node',
  );
  $handler->display->display_options['style_options']['default'] = 'title';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_accepted' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_speakers' => array(
      'align' => '',
      'separator' => '',
    ),
    'field_experience' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'field_track' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'No sessions';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'There are no sessions with this status.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Status */
  $handler->display->display_options['fields']['field_accepted']['id'] = 'field_accepted';
  $handler->display->display_options['fields']['field_accepted']['table'] = 'field_data_field_accepted';
  $handler->display->display_options['fields']['field_accepted']['field'] = 'field_accepted';
  $handler->display->display_options['fields']['field_accepted']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_accepted']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_accepted']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_accepted']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_accepted']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_accepted']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_accepted']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_accepted']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_accepted']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_accepted']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_accepted']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_accepted']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_accepted']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_accepted']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_accepted']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_accepted']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_accepted']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_accepted']['field_api_classes'] = 0;
  /* Field: Content: Speaker(s) */
  $handler->display->display_options['fields']['field_speakers']['id'] = 'field_speakers';
  $handler->display->display_options['fields']['field_speakers']['table'] = 'field_data_field_speakers';
  $handler->display->display_options['fields']['field_speakers']['field'] = 'field_speakers';
  $handler->display->display_options['fields']['field_speakers']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_speakers']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_speakers']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_speakers']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_speakers']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_speakers']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_speakers']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_speakers']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_speakers']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_speakers']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_speakers']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_speakers']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_speakers']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_speakers']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_speakers']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_speakers']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_speakers']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_speakers']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_speakers']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_speakers']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_speakers']['field_api_classes'] = 0;
  /* Field: Content: Experience level */
  $handler->display->display_options['fields']['field_experience']['id'] = 'field_experience';
  $handler->display->display_options['fields']['field_experience']['table'] = 'field_data_field_experience';
  $handler->display->display_options['fields']['field_experience']['field'] = 'field_experience';
  $handler->display->display_options['fields']['field_experience']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_experience']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_experience']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_experience']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_experience']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_experience']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_experience']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_experience']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_experience']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_experience']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_experience']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_experience']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_experience']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_experience']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_experience']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_experience']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_experience']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_experience']['field_api_classes'] = 0;
  /* Field: Content: Track */
  $handler->display->display_options['fields']['field_track']['id'] = 'field_track';
  $handler->display->display_options['fields']['field_track']['table'] = 'field_data_field_track';
  $handler->display->display_options['fields']['field_track']['field'] = 'field_track';
  $handler->display->display_options['fields']['field_track']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_track']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_track']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_track']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_track']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_track']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_track']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_track']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_track']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_track']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_track']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_track']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_track']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_track']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_track']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_track']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_track']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_track']['field_api_classes'] = 0;
  /* Field: Node: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['external'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['edit_node']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['edit_node']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['edit_node']['alter']['html'] = 0;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['edit_node']['hide_empty'] = 0;
  $handler->display->display_options['fields']['edit_node']['empty_zero'] = 0;
  $handler->display->display_options['fields']['edit_node']['hide_alter_empty'] = 0;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'session' => 'session',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Status (field_accepted) */
  $handler->display->display_options['filters']['field_accepted_value']['id'] = 'field_accepted_value';
  $handler->display->display_options['filters']['field_accepted_value']['table'] = 'field_data_field_accepted';
  $handler->display->display_options['filters']['field_accepted_value']['field'] = 'field_accepted_value';
  $handler->display->display_options['filters']['field_accepted_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_accepted_value']['group'] = 1;
  /* Filter criterion: Content: Track (field_track) */
  $handler->display->display_options['filters']['field_track_value']['id'] = 'field_track_value';
  $handler->display->display_options['filters']['field_track_value']['table'] = 'field_data_field_track';
  $handler->display->display_options['filters']['field_track_value']['field'] = 'field_track_value';
  $handler->display->display_options['filters']['field_track_value']['group'] = 1;
  $handler->display->display_options['filters']['field_track_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_track_value']['expose']['operator_id'] = 'field_track_value_op';
  $handler->display->display_options['filters']['field_track_value']['expose']['label'] = 'Track';
  $handler->display->display_options['filters']['field_track_value']['expose']['operator'] = 'field_track_value_op';
  $handler->display->display_options['filters']['field_track_value']['expose']['identifier'] = 'track';
  $handler->display->display_options['filters']['field_track_value']['expose']['multiple'] = 1;
  $handler->display->display_options['filters']['field_track_value']['expose']['reduce'] = 0;
  /* Filter criterion: Search: Search Terms */
  $handler->display->display_options['filters']['keys']['id'] = 'keys';
  $handler->display->display_options['filters']['keys']['table'] = 'search_index';
  $handler->display->display_options['filters']['keys']['field'] = 'keys';
  $handler->display->display_options['filters']['keys']['group'] = 1;
  $handler->display->display_options['filters']['keys']['exposed'] = TRUE;
  $handler->display->display_options['filters']['keys']['expose']['operator_id'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['label'] = 'Filter by keywords:';
  $handler->display->display_options['filters']['keys']['expose']['operator'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['identifier'] = 'keys';
  $handler->display->display_options['filters']['keys']['expose']['multiple'] = FALSE;
  /* Filter criterion: Content: Experience level (field_experience) */
  $handler->display->display_options['filters']['field_experience_value']['id'] = 'field_experience_value';
  $handler->display->display_options['filters']['field_experience_value']['table'] = 'field_data_field_experience';
  $handler->display->display_options['filters']['field_experience_value']['field'] = 'field_experience_value';
  $handler->display->display_options['filters']['field_experience_value']['group'] = 1;
  $handler->display->display_options['filters']['field_experience_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_experience_value']['expose']['operator_id'] = 'field_experience_value_op';
  $handler->display->display_options['filters']['field_experience_value']['expose']['label'] = 'Experience level';
  $handler->display->display_options['filters']['field_experience_value']['expose']['operator'] = 'field_experience_value_op';
  $handler->display->display_options['filters']['field_experience_value']['expose']['identifier'] = 'experience_level';
  $handler->display->display_options['filters']['field_experience_value']['expose']['remember'] = 1;
  $handler->display->display_options['filters']['field_experience_value']['expose']['multiple'] = 1;
  $handler->display->display_options['filters']['field_experience_value']['expose']['reduce'] = 0;

  /* Display: Page: Accepted */
  $handler = $view->new_display('page', 'Page: Accepted', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Accepted Sessions';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'view-grouped-list sessions-list sessions-accepted';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'No accepted sessions';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'No sessions have been accepted yet. When you accept unprocessed sessions, they will show up here.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'session' => 'session',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Status (field_accepted) */
  $handler->display->display_options['filters']['field_accepted_value']['id'] = 'field_accepted_value';
  $handler->display->display_options['filters']['field_accepted_value']['table'] = 'field_data_field_accepted';
  $handler->display->display_options['filters']['field_accepted_value']['field'] = 'field_accepted_value';
  $handler->display->display_options['filters']['field_accepted_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_accepted_value']['group'] = 1;
  /* Filter criterion: Content: Room (field_session_room) */
  $handler->display->display_options['filters']['field_session_room_nid']['id'] = 'field_session_room_nid';
  $handler->display->display_options['filters']['field_session_room_nid']['table'] = 'field_data_field_session_room';
  $handler->display->display_options['filters']['field_session_room_nid']['field'] = 'field_session_room_nid';
  $handler->display->display_options['filters']['field_session_room_nid']['operator'] = 'empty';
  $handler->display->display_options['filters']['field_session_room_nid']['group'] = 1;
  /* Filter criterion: Content: Time slot (field_session_slot) */
  $handler->display->display_options['filters']['field_session_slot_nid']['id'] = 'field_session_slot_nid';
  $handler->display->display_options['filters']['field_session_slot_nid']['table'] = 'field_data_field_session_slot';
  $handler->display->display_options['filters']['field_session_slot_nid']['field'] = 'field_session_slot_nid';
  $handler->display->display_options['filters']['field_session_slot_nid']['operator'] = 'empty';
  $handler->display->display_options['filters']['field_session_slot_nid']['group'] = 1;
  /* Filter criterion: Content: Track (field_track) */
  $handler->display->display_options['filters']['field_track_value']['id'] = 'field_track_value';
  $handler->display->display_options['filters']['field_track_value']['table'] = 'field_data_field_track';
  $handler->display->display_options['filters']['field_track_value']['field'] = 'field_track_value';
  $handler->display->display_options['filters']['field_track_value']['group'] = 1;
  $handler->display->display_options['filters']['field_track_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_track_value']['expose']['operator_id'] = 'field_track_value_op';
  $handler->display->display_options['filters']['field_track_value']['expose']['label'] = 'Track';
  $handler->display->display_options['filters']['field_track_value']['expose']['operator'] = 'field_track_value_op';
  $handler->display->display_options['filters']['field_track_value']['expose']['identifier'] = 'track';
  $handler->display->display_options['filters']['field_track_value']['expose']['multiple'] = 1;
  $handler->display->display_options['filters']['field_track_value']['expose']['reduce'] = 0;
  /* Filter criterion: Search: Search Terms */
  $handler->display->display_options['filters']['keys']['id'] = 'keys';
  $handler->display->display_options['filters']['keys']['table'] = 'search_index';
  $handler->display->display_options['filters']['keys']['field'] = 'keys';
  $handler->display->display_options['filters']['keys']['group'] = 1;
  $handler->display->display_options['filters']['keys']['exposed'] = TRUE;
  $handler->display->display_options['filters']['keys']['expose']['operator_id'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['label'] = 'Filter by keywords:';
  $handler->display->display_options['filters']['keys']['expose']['operator'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['identifier'] = 'keys';
  $handler->display->display_options['filters']['keys']['expose']['multiple'] = FALSE;
  /* Filter criterion: Content: Experience level (field_experience) */
  $handler->display->display_options['filters']['field_experience_value']['id'] = 'field_experience_value';
  $handler->display->display_options['filters']['field_experience_value']['table'] = 'field_data_field_experience';
  $handler->display->display_options['filters']['field_experience_value']['field'] = 'field_experience_value';
  $handler->display->display_options['filters']['field_experience_value']['group'] = 1;
  $handler->display->display_options['filters']['field_experience_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_experience_value']['expose']['operator_id'] = 'field_experience_value_op';
  $handler->display->display_options['filters']['field_experience_value']['expose']['label'] = 'Experience level';
  $handler->display->display_options['filters']['field_experience_value']['expose']['operator'] = 'field_experience_value_op';
  $handler->display->display_options['filters']['field_experience_value']['expose']['identifier'] = 'experience_level';
  $handler->display->display_options['filters']['field_experience_value']['expose']['remember'] = 1;
  $handler->display->display_options['filters']['field_experience_value']['expose']['multiple'] = 1;
  $handler->display->display_options['filters']['field_experience_value']['expose']['reduce'] = 0;
  $handler->display->display_options['path'] = 'conference-admin/sessions/accepted';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Accepted Sessions';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-menu-conference-admin';
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Admin Sessions';
  $handler->display->display_options['tab_options']['weight'] = '0';

  /* Display: Page: Declined */
  $handler = $view->new_display('page', 'Page: Declined', 'page_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Declined Sessions';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'view-grouped-list sessions-list sessions-declined';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'No declined sessions';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'No sessions have been declined yet. When you decline unprocessed sessions, they will show up here.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'session' => 'session',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Status (field_accepted) */
  $handler->display->display_options['filters']['field_accepted_value']['id'] = 'field_accepted_value';
  $handler->display->display_options['filters']['field_accepted_value']['table'] = 'field_data_field_accepted';
  $handler->display->display_options['filters']['field_accepted_value']['field'] = 'field_accepted_value';
  $handler->display->display_options['filters']['field_accepted_value']['value'] = array(
    2 => '2',
  );
  $handler->display->display_options['filters']['field_accepted_value']['group'] = 1;
  /* Filter criterion: Content: Track (field_track) */
  $handler->display->display_options['filters']['field_track_value']['id'] = 'field_track_value';
  $handler->display->display_options['filters']['field_track_value']['table'] = 'field_data_field_track';
  $handler->display->display_options['filters']['field_track_value']['field'] = 'field_track_value';
  $handler->display->display_options['filters']['field_track_value']['group'] = 1;
  $handler->display->display_options['filters']['field_track_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_track_value']['expose']['operator_id'] = 'field_track_value_op';
  $handler->display->display_options['filters']['field_track_value']['expose']['label'] = 'Track';
  $handler->display->display_options['filters']['field_track_value']['expose']['operator'] = 'field_track_value_op';
  $handler->display->display_options['filters']['field_track_value']['expose']['identifier'] = 'track';
  $handler->display->display_options['filters']['field_track_value']['expose']['multiple'] = 1;
  $handler->display->display_options['filters']['field_track_value']['expose']['reduce'] = 0;
  /* Filter criterion: Search: Search Terms */
  $handler->display->display_options['filters']['keys']['id'] = 'keys';
  $handler->display->display_options['filters']['keys']['table'] = 'search_index';
  $handler->display->display_options['filters']['keys']['field'] = 'keys';
  $handler->display->display_options['filters']['keys']['group'] = 1;
  $handler->display->display_options['filters']['keys']['exposed'] = TRUE;
  $handler->display->display_options['filters']['keys']['expose']['operator_id'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['label'] = 'Filter by keywords:';
  $handler->display->display_options['filters']['keys']['expose']['operator'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['identifier'] = 'keys';
  $handler->display->display_options['filters']['keys']['expose']['multiple'] = FALSE;
  /* Filter criterion: Content: Experience level (field_experience) */
  $handler->display->display_options['filters']['field_experience_value']['id'] = 'field_experience_value';
  $handler->display->display_options['filters']['field_experience_value']['table'] = 'field_data_field_experience';
  $handler->display->display_options['filters']['field_experience_value']['field'] = 'field_experience_value';
  $handler->display->display_options['filters']['field_experience_value']['group'] = 1;
  $handler->display->display_options['filters']['field_experience_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_experience_value']['expose']['operator_id'] = 'field_experience_value_op';
  $handler->display->display_options['filters']['field_experience_value']['expose']['label'] = 'Experience level';
  $handler->display->display_options['filters']['field_experience_value']['expose']['operator'] = 'field_experience_value_op';
  $handler->display->display_options['filters']['field_experience_value']['expose']['identifier'] = 'experience_level';
  $handler->display->display_options['filters']['field_experience_value']['expose']['remember'] = 1;
  $handler->display->display_options['filters']['field_experience_value']['expose']['multiple'] = 1;
  $handler->display->display_options['filters']['field_experience_value']['expose']['reduce'] = 0;
  $handler->display->display_options['path'] = 'conference-admin/sessions/declined';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Declined Sessions';
  $handler->display->display_options['menu']['weight'] = '-5';
  $handler->display->display_options['menu']['name'] = 'menu-menu-conference-admin';

  /* Display: Page: Unprocessed */
  $handler = $view->new_display('page', 'Page: Unprocessed', 'page_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Unprocessed Sessions';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'view-grouped-list sessions-list sessions-unprocessed';
  $handler->display->display_options['display_description'] = 'These sessions have not yet been approved or declined. ';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'No unprocessed sessions';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'There are no sessions to process. Relax a bit!';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'session' => 'session',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Status (field_accepted) */
  $handler->display->display_options['filters']['field_accepted_value']['id'] = 'field_accepted_value';
  $handler->display->display_options['filters']['field_accepted_value']['table'] = 'field_data_field_accepted';
  $handler->display->display_options['filters']['field_accepted_value']['field'] = 'field_accepted_value';
  $handler->display->display_options['filters']['field_accepted_value']['value'] = array(
    0 => '0',
  );
  $handler->display->display_options['filters']['field_accepted_value']['group'] = 1;
  /* Filter criterion: Content: Track (field_track) */
  $handler->display->display_options['filters']['field_track_value']['id'] = 'field_track_value';
  $handler->display->display_options['filters']['field_track_value']['table'] = 'field_data_field_track';
  $handler->display->display_options['filters']['field_track_value']['field'] = 'field_track_value';
  $handler->display->display_options['filters']['field_track_value']['group'] = 1;
  $handler->display->display_options['filters']['field_track_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_track_value']['expose']['operator_id'] = 'field_track_value_op';
  $handler->display->display_options['filters']['field_track_value']['expose']['label'] = 'Track';
  $handler->display->display_options['filters']['field_track_value']['expose']['operator'] = 'field_track_value_op';
  $handler->display->display_options['filters']['field_track_value']['expose']['identifier'] = 'track';
  $handler->display->display_options['filters']['field_track_value']['expose']['multiple'] = 1;
  $handler->display->display_options['filters']['field_track_value']['expose']['reduce'] = 0;
  /* Filter criterion: Search: Search Terms */
  $handler->display->display_options['filters']['keys']['id'] = 'keys';
  $handler->display->display_options['filters']['keys']['table'] = 'search_index';
  $handler->display->display_options['filters']['keys']['field'] = 'keys';
  $handler->display->display_options['filters']['keys']['group'] = 1;
  $handler->display->display_options['filters']['keys']['exposed'] = TRUE;
  $handler->display->display_options['filters']['keys']['expose']['operator_id'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['label'] = 'Filter by keywords:';
  $handler->display->display_options['filters']['keys']['expose']['operator'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['identifier'] = 'keys';
  $handler->display->display_options['filters']['keys']['expose']['multiple'] = FALSE;
  /* Filter criterion: Content: Experience level (field_experience) */
  $handler->display->display_options['filters']['field_experience_value']['id'] = 'field_experience_value';
  $handler->display->display_options['filters']['field_experience_value']['table'] = 'field_data_field_experience';
  $handler->display->display_options['filters']['field_experience_value']['field'] = 'field_experience_value';
  $handler->display->display_options['filters']['field_experience_value']['group'] = 1;
  $handler->display->display_options['filters']['field_experience_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_experience_value']['expose']['operator_id'] = 'field_experience_value_op';
  $handler->display->display_options['filters']['field_experience_value']['expose']['label'] = 'Experience level';
  $handler->display->display_options['filters']['field_experience_value']['expose']['operator'] = 'field_experience_value_op';
  $handler->display->display_options['filters']['field_experience_value']['expose']['identifier'] = 'experience_level';
  $handler->display->display_options['filters']['field_experience_value']['expose']['remember'] = 1;
  $handler->display->display_options['filters']['field_experience_value']['expose']['multiple'] = 1;
  $handler->display->display_options['filters']['field_experience_value']['expose']['reduce'] = 0;
  $handler->display->display_options['path'] = 'conference-admin/sessions/unprocessed';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'Unprocessed sessions';
  $handler->display->display_options['menu']['weight'] = '-10';
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Administer Sessions';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'menu-menu-conference-admin';

  /* Display: Page: Scheduled */
  $handler = $view->new_display('page', 'Page: Scheduled', 'page_4');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Scheduled Sessions';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'No scheduled sessions';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'No sessions have been scheduled yet. Assign a time slot and room to an accepted session to schedule it.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'session' => 'session',
  );
  $handler->display->display_options['filters']['type']['group'] = 0;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 0;
  /* Filter criterion: Content: Room (field_session_room) */
  $handler->display->display_options['filters']['field_session_room_nid']['id'] = 'field_session_room_nid';
  $handler->display->display_options['filters']['field_session_room_nid']['table'] = 'field_data_field_session_room';
  $handler->display->display_options['filters']['field_session_room_nid']['field'] = 'field_session_room_nid';
  $handler->display->display_options['filters']['field_session_room_nid']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_session_room_nid']['group'] = 0;
  $handler->display->display_options['filters']['field_session_room_nid']['expose']['operator_id'] = 'field_session_room_nid_op';
  $handler->display->display_options['filters']['field_session_room_nid']['expose']['label'] = 'Room';
  $handler->display->display_options['filters']['field_session_room_nid']['expose']['operator'] = 'field_session_room_nid_op';
  $handler->display->display_options['filters']['field_session_room_nid']['expose']['identifier'] = 'room';
  $handler->display->display_options['filters']['field_session_room_nid']['expose']['reduce'] = 0;
  /* Filter criterion: Content: Time slot (field_session_slot) */
  $handler->display->display_options['filters']['field_session_slot_nid']['id'] = 'field_session_slot_nid';
  $handler->display->display_options['filters']['field_session_slot_nid']['table'] = 'field_data_field_session_slot';
  $handler->display->display_options['filters']['field_session_slot_nid']['field'] = 'field_session_slot_nid';
  $handler->display->display_options['filters']['field_session_slot_nid']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_session_slot_nid']['group'] = 0;
  /* Filter criterion: Content: Track (field_track) */
  $handler->display->display_options['filters']['field_track_value']['id'] = 'field_track_value';
  $handler->display->display_options['filters']['field_track_value']['table'] = 'field_data_field_track';
  $handler->display->display_options['filters']['field_track_value']['field'] = 'field_track_value';
  $handler->display->display_options['filters']['field_track_value']['group'] = 0;
  $handler->display->display_options['filters']['field_track_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_track_value']['expose']['operator_id'] = 'field_track_value_op';
  $handler->display->display_options['filters']['field_track_value']['expose']['label'] = 'Track';
  $handler->display->display_options['filters']['field_track_value']['expose']['operator'] = 'field_track_value_op';
  $handler->display->display_options['filters']['field_track_value']['expose']['identifier'] = 'track';
  $handler->display->display_options['filters']['field_track_value']['expose']['multiple'] = 1;
  $handler->display->display_options['filters']['field_track_value']['expose']['reduce'] = 0;
  /* Filter criterion: Search: Search Terms */
  $handler->display->display_options['filters']['keys']['id'] = 'keys';
  $handler->display->display_options['filters']['keys']['table'] = 'search_index';
  $handler->display->display_options['filters']['keys']['field'] = 'keys';
  $handler->display->display_options['filters']['keys']['group'] = 0;
  $handler->display->display_options['filters']['keys']['exposed'] = TRUE;
  $handler->display->display_options['filters']['keys']['expose']['operator_id'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['label'] = 'Filter by keywords:';
  $handler->display->display_options['filters']['keys']['expose']['operator'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['identifier'] = 'keys';
  $handler->display->display_options['filters']['keys']['expose']['multiple'] = FALSE;
  /* Filter criterion: Content: Experience level (field_experience) */
  $handler->display->display_options['filters']['field_experience_value']['id'] = 'field_experience_value';
  $handler->display->display_options['filters']['field_experience_value']['table'] = 'field_data_field_experience';
  $handler->display->display_options['filters']['field_experience_value']['field'] = 'field_experience_value';
  $handler->display->display_options['filters']['field_experience_value']['group'] = 0;
  $handler->display->display_options['filters']['field_experience_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_experience_value']['expose']['operator_id'] = 'field_experience_value_op';
  $handler->display->display_options['filters']['field_experience_value']['expose']['label'] = 'Experience level';
  $handler->display->display_options['filters']['field_experience_value']['expose']['operator'] = 'field_experience_value_op';
  $handler->display->display_options['filters']['field_experience_value']['expose']['identifier'] = 'experience_level';
  $handler->display->display_options['filters']['field_experience_value']['expose']['remember'] = 1;
  $handler->display->display_options['filters']['field_experience_value']['expose']['multiple'] = 1;
  $handler->display->display_options['filters']['field_experience_value']['expose']['reduce'] = 0;
  $handler->display->display_options['path'] = 'conference-admin/sessions/scheduled';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Scheduled sessions';
  $handler->display->display_options['menu']['weight'] = '5';
  $handler->display->display_options['menu']['name'] = 'menu-menu-conference-admin';
  $export['sessions_admin'] = $view;

  $view = new view;
  $view->name = 'sessions_admin_contact';
  $view->description = 'Allows conference administrators to mass email various groups of speakers.';
  $view->tag = 'cod session';
  $view->base_table = 'node';
  $view->human_name = 'sessions_admin_contact';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'General speaker mail';
  $handler->display->display_options['css_class'] = 'view-grouped-list sessions-list';
  $handler->display->display_options['link_display'] = 'page_3';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'edit field_accepted';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '130';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = '';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'counter' => 'counter',
    'nid' => 'nid',
    'title' => 'title',
    'field_profile_first' => 'field_profile_first',
    'field_profile_last' => 'field_profile_last',
    'name' => 'name',
    'mail' => 'mail',
    'field_speakers' => 'field_speakers',
  );
  $handler->display->display_options['style_options']['default'] = 'title';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'counter' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_profile_first' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_profile_last' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'mail' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_speakers' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 1;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'No speakers...';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'There are no speakers in this category.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  /* Relationship: Content: Speaker(s) (field_speakers) */
  $handler->display->display_options['relationships']['field_speakers_uid']['id'] = 'field_speakers_uid';
  $handler->display->display_options['relationships']['field_speakers_uid']['table'] = 'field_data_field_speakers';
  $handler->display->display_options['relationships']['field_speakers_uid']['field'] = 'field_speakers_uid';
  $handler->display->display_options['relationships']['field_speakers_uid']['label'] = 'Speaker(s)';
  $handler->display->display_options['relationships']['field_speakers_uid']['required'] = 1;
  $handler->display->display_options['relationships']['field_speakers_uid']['delta'] = '-1';
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = 'Select';
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['external'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['alter']['html'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['hide_empty'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['empty_zero'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['operations'] = array(
    'action::node_assign_owner_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::system_message_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_make_sticky_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_make_unsticky_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_argument_selector_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_promote_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_publish_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::system_goto_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpromote_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_save_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::system_send_email_action' => array(
      'selected' => 1,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 1,
      'label' => 'Email Speakers',
    ),
    'action::node_unpublish_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpublish_by_keyword_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['display_result'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['merge_single_action'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo']['force_single'] = 0;
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = 'Row #';
  $handler->display->display_options['fields']['counter']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['counter']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['counter']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['counter']['alter']['external'] = 0;
  $handler->display->display_options['fields']['counter']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['counter']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['counter']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['counter']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['counter']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['counter']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['counter']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['counter']['alter']['html'] = 0;
  $handler->display->display_options['fields']['counter']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['counter']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['counter']['hide_empty'] = 0;
  $handler->display->display_options['fields']['counter']['empty_zero'] = 0;
  $handler->display->display_options['fields']['counter']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'ID';
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['nid']['link_to_node'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: User: First name */
  $handler->display->display_options['fields']['field_profile_first']['id'] = 'field_profile_first';
  $handler->display->display_options['fields']['field_profile_first']['table'] = 'field_data_field_profile_first';
  $handler->display->display_options['fields']['field_profile_first']['field'] = 'field_profile_first';
  $handler->display->display_options['fields']['field_profile_first']['relationship'] = 'field_speakers_uid';
  $handler->display->display_options['fields']['field_profile_first']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_profile_first']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_profile_first']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_profile_first']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_profile_first']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_profile_first']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_profile_first']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_profile_first']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_profile_first']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_profile_first']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_profile_first']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_profile_first']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_profile_first']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_profile_first']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_profile_first']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_profile_first']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_profile_first']['hide_alter_empty'] = 0;
  /* Field: User: Last name */
  $handler->display->display_options['fields']['field_profile_last']['id'] = 'field_profile_last';
  $handler->display->display_options['fields']['field_profile_last']['table'] = 'field_data_field_profile_last';
  $handler->display->display_options['fields']['field_profile_last']['field'] = 'field_profile_last';
  $handler->display->display_options['fields']['field_profile_last']['relationship'] = 'field_speakers_uid';
  $handler->display->display_options['fields']['field_profile_last']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_profile_last']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_profile_last']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_profile_last']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_profile_last']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_profile_last']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_profile_last']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_profile_last']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_profile_last']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_profile_last']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_profile_last']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_profile_last']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_profile_last']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_profile_last']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_profile_last']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_profile_last']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_profile_last']['hide_alter_empty'] = 0;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'field_speakers_uid';
  $handler->display->display_options['fields']['name']['label'] = 'Username';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['name']['link_to_user'] = 1;
  $handler->display->display_options['fields']['name']['overwrite_anonymous'] = 0;
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['relationship'] = 'field_speakers_uid';
  $handler->display->display_options['fields']['mail']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['mail']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['mail']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['mail']['alter']['external'] = 0;
  $handler->display->display_options['fields']['mail']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['mail']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['mail']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['mail']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['mail']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['mail']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['mail']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['mail']['alter']['html'] = 0;
  $handler->display->display_options['fields']['mail']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['mail']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['mail']['hide_empty'] = 0;
  $handler->display->display_options['fields']['mail']['empty_zero'] = 0;
  $handler->display->display_options['fields']['mail']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['mail']['link_to_user'] = 0;
  /* Field: Content: Speaker(s) */
  $handler->display->display_options['fields']['field_speakers']['id'] = 'field_speakers';
  $handler->display->display_options['fields']['field_speakers']['table'] = 'field_data_field_speakers';
  $handler->display->display_options['fields']['field_speakers']['field'] = 'field_speakers';
  $handler->display->display_options['fields']['field_speakers']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_speakers']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_speakers']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_speakers']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_speakers']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_speakers']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_speakers']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_speakers']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_speakers']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_speakers']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_speakers']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_speakers']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_speakers']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_speakers']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_speakers']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_speakers']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_speakers']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_speakers']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_speakers']['delta_limit'] = '5';
  $handler->display->display_options['fields']['field_speakers']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_speakers']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_speakers']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_speakers']['field_api_classes'] = 0;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'session' => 'session',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Status (field_accepted) */
  $handler->display->display_options['filters']['field_accepted_value']['id'] = 'field_accepted_value';
  $handler->display->display_options['filters']['field_accepted_value']['table'] = 'field_data_field_accepted';
  $handler->display->display_options['filters']['field_accepted_value']['field'] = 'field_accepted_value';
  $handler->display->display_options['filters']['field_accepted_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_accepted_value']['group'] = 1;

  /* Display: Page: Unprocessed */
  $handler = $view->new_display('page', 'Page: Unprocessed', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Email speakers of unprocessed sessions';
  $handler->display->display_options['display_description'] = 'Email speakers of unprocessed sessions';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'Unprocessed speakers';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = 'Each speaker will receive one email per unprocessed session submission.';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  $handler->display->display_options['header']['area']['tokenize'] = 0;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'No unprocessed speakers';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'There are no unprocessed speakers at the moment. ';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'session' => 'session',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Status (field_accepted) */
  $handler->display->display_options['filters']['field_accepted_value']['id'] = 'field_accepted_value';
  $handler->display->display_options['filters']['field_accepted_value']['table'] = 'field_data_field_accepted';
  $handler->display->display_options['filters']['field_accepted_value']['field'] = 'field_accepted_value';
  $handler->display->display_options['filters']['field_accepted_value']['value'] = array(
    0 => '0',
  );
  $handler->display->display_options['filters']['field_accepted_value']['group'] = 1;
  $handler->display->display_options['path'] = 'conference-admin/contact-speakers/unprocessed';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'Unprocessed';
  $handler->display->display_options['menu']['description'] = 'Email speakers of unprocessed sessions.';
  $handler->display->display_options['menu']['weight'] = '-30';
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Contact Speakers';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'menu-menu-conference-admin';

  /* Display: Page: Declined */
  $handler = $view->new_display('page', 'Page: Declined', 'page_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Email speakers of declined sessions';
  $handler->display->display_options['display_description'] = 'Email speakers of declined sessions';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'Declined speakers';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = 'Each speaker will receive one email per declined session submission.';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  $handler->display->display_options['header']['area']['tokenize'] = 0;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'No declined speakers';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'There are no declined speakers at the moment.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'session' => 'session',
  );
  /* Filter criterion: Content: Status (field_accepted) */
  $handler->display->display_options['filters']['field_accepted_value']['id'] = 'field_accepted_value';
  $handler->display->display_options['filters']['field_accepted_value']['table'] = 'field_data_field_accepted';
  $handler->display->display_options['filters']['field_accepted_value']['field'] = 'field_accepted_value';
  $handler->display->display_options['filters']['field_accepted_value']['value'] = array(
    2 => '2',
  );
  $handler->display->display_options['path'] = 'conference-admin/contact-speakers/declined';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Declined';
  $handler->display->display_options['menu']['weight'] = '-25';
  $handler->display->display_options['menu']['name'] = 'menu-menu-conference-admin';

  /* Display: Page: Accepted */
  $handler = $view->new_display('page', 'Page: Accepted', 'page_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Email speakers of accepted sessions';
  $handler->display->display_options['display_description'] = 'Email speakers of accepted sessions';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'Accepted speakers';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = 'Each speaker will receive one email per accepted session submission. Note: Only sessions that have not yet been scheduled are displayed here.';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  $handler->display->display_options['header']['area']['tokenize'] = 0;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'No accepted speakers';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'There are no accepted speakers at the moment. Try <a href="/conference-admin/sessions">reviewing sessions</a> to accept or decline them.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'session' => 'session',
  );
  /* Filter criterion: Content: Status (field_accepted) */
  $handler->display->display_options['filters']['field_accepted_value']['id'] = 'field_accepted_value';
  $handler->display->display_options['filters']['field_accepted_value']['table'] = 'field_data_field_accepted';
  $handler->display->display_options['filters']['field_accepted_value']['field'] = 'field_accepted_value';
  $handler->display->display_options['filters']['field_accepted_value']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Content: Room (field_session_room) */
  $handler->display->display_options['filters']['field_session_room_nid']['id'] = 'field_session_room_nid';
  $handler->display->display_options['filters']['field_session_room_nid']['table'] = 'field_data_field_session_room';
  $handler->display->display_options['filters']['field_session_room_nid']['field'] = 'field_session_room_nid';
  $handler->display->display_options['filters']['field_session_room_nid']['operator'] = 'empty';
  $handler->display->display_options['path'] = 'conference-admin/contact-speakers/accepted';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Accepted';
  $handler->display->display_options['menu']['weight'] = '-20';
  $handler->display->display_options['menu']['name'] = 'menu-menu-conference-admin';

  /* Display: Page: Scheduled */
  $handler = $view->new_display('page', 'Page: Scheduled', 'page_4');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Email speakers of scheduled sessions';
  $handler->display->display_options['display_description'] = 'Email speakers of scheduled sessions';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'Scheduled speakers';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = 'Each speaker will receive one email per scheduled session.';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  $handler->display->display_options['header']['area']['tokenize'] = 0;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'No speakers...';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'There are no scheduled speakers at the moment.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'session' => 'session',
  );
  /* Filter criterion: Content: Status (field_accepted) */
  $handler->display->display_options['filters']['field_accepted_value']['id'] = 'field_accepted_value';
  $handler->display->display_options['filters']['field_accepted_value']['table'] = 'field_data_field_accepted';
  $handler->display->display_options['filters']['field_accepted_value']['field'] = 'field_accepted_value';
  $handler->display->display_options['filters']['field_accepted_value']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Content: Room (field_session_room) */
  $handler->display->display_options['filters']['field_session_room_nid']['id'] = 'field_session_room_nid';
  $handler->display->display_options['filters']['field_session_room_nid']['table'] = 'field_data_field_session_room';
  $handler->display->display_options['filters']['field_session_room_nid']['field'] = 'field_session_room_nid';
  $handler->display->display_options['filters']['field_session_room_nid']['operator'] = 'not empty';
  /* Filter criterion: Content: Time slot (field_session_slot) */
  $handler->display->display_options['filters']['field_session_slot_nid']['id'] = 'field_session_slot_nid';
  $handler->display->display_options['filters']['field_session_slot_nid']['table'] = 'field_data_field_session_slot';
  $handler->display->display_options['filters']['field_session_slot_nid']['field'] = 'field_session_slot_nid';
  $handler->display->display_options['filters']['field_session_slot_nid']['operator'] = 'not empty';
  $handler->display->display_options['path'] = 'conference-admin/contact-speakers/scheduled';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Scheduled';
  $handler->display->display_options['menu']['weight'] = '-15';
  $handler->display->display_options['menu']['name'] = 'menu-menu-conference-admin';

  /* Display: Page: Unconfirmed */
  $handler = $view->new_display('page', 'Page: Unconfirmed', 'page_5');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Email speakers who have not confirmed their scheduled session';
  $handler->display->display_options['display_description'] = 'Email speakers who have not confirmed their scheduled session';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'Unconfirmed speakers';
  $handler->display->display_options['header']['area']['empty'] = FALSE;
  $handler->display->display_options['header']['area']['content'] = '<p class="speakers-unconfirmed-header">These sessions have been accepted and scheduled, but the speakers haven\'t confirmed.</p>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['header']['area']['tokenize'] = 0;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Speaker(s) (field_speakers) */
  $handler->display->display_options['relationships']['field_speakers_uid']['id'] = 'field_speakers_uid';
  $handler->display->display_options['relationships']['field_speakers_uid']['table'] = 'field_data_field_speakers';
  $handler->display->display_options['relationships']['field_speakers_uid']['field'] = 'field_speakers_uid';
  $handler->display->display_options['relationships']['field_speakers_uid']['label'] = 'Speaker(s)';
  $handler->display->display_options['relationships']['field_speakers_uid']['required'] = 1;
  $handler->display->display_options['relationships']['field_speakers_uid']['delta'] = '-1';
  /* Relationship: Flags: session_confirm */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['label'] = 'session_confirm';
  $handler->display->display_options['relationships']['flag_content_rel']['required'] = 0;
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'session_confirm';
  $handler->display->display_options['relationships']['flag_content_rel']['user_scope'] = 'any';
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'session' => 'session',
  );
  /* Filter criterion: Content: Status (field_accepted) */
  $handler->display->display_options['filters']['field_accepted_value']['id'] = 'field_accepted_value';
  $handler->display->display_options['filters']['field_accepted_value']['table'] = 'field_data_field_accepted';
  $handler->display->display_options['filters']['field_accepted_value']['field'] = 'field_accepted_value';
  $handler->display->display_options['filters']['field_accepted_value']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Content: Room (field_session_room) */
  $handler->display->display_options['filters']['field_session_room_nid']['id'] = 'field_session_room_nid';
  $handler->display->display_options['filters']['field_session_room_nid']['table'] = 'field_data_field_session_room';
  $handler->display->display_options['filters']['field_session_room_nid']['field'] = 'field_session_room_nid';
  $handler->display->display_options['filters']['field_session_room_nid']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_session_room_nid']['group'] = '0';
  /* Filter criterion: Flags: Flagged */
  $handler->display->display_options['filters']['flagged']['id'] = 'flagged';
  $handler->display->display_options['filters']['flagged']['table'] = 'flag_content';
  $handler->display->display_options['filters']['flagged']['field'] = 'flagged';
  $handler->display->display_options['filters']['flagged']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['filters']['flagged']['value'] = '0';
  /* Filter criterion: Content: Time slot (field_session_slot) */
  $handler->display->display_options['filters']['field_session_slot_nid']['id'] = 'field_session_slot_nid';
  $handler->display->display_options['filters']['field_session_slot_nid']['table'] = 'field_data_field_session_slot';
  $handler->display->display_options['filters']['field_session_slot_nid']['field'] = 'field_session_slot_nid';
  $handler->display->display_options['filters']['field_session_slot_nid']['operator'] = 'not empty';
  $handler->display->display_options['path'] = 'conference-admin/contact-speakers/unconfirmed';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Unconfirmed';
  $handler->display->display_options['menu']['weight'] = '-10';
  $handler->display->display_options['menu']['name'] = 'menu-menu-conference-admin';

  /* Display: Page: Confirmed */
  $handler = $view->new_display('page', 'Page: Confirmed', 'page_6');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Email speakers who have confirmed for their session';
  $handler->display->display_options['display_description'] = 'Email speakers who have confirmed for their session';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'Confirmed speakers';
  $handler->display->display_options['header']['area']['empty'] = FALSE;
  $handler->display->display_options['header']['area']['content'] = '<p class="speakers-confirmed-header">Speakers listed here have confirmed that they are able to present at the scheduled date and time.</p>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['header']['area']['tokenize'] = 0;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'No confirmed speakers';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'There are no confirmed session speakers yet.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Speaker(s) (field_speakers) */
  $handler->display->display_options['relationships']['field_speakers_uid']['id'] = 'field_speakers_uid';
  $handler->display->display_options['relationships']['field_speakers_uid']['table'] = 'field_data_field_speakers';
  $handler->display->display_options['relationships']['field_speakers_uid']['field'] = 'field_speakers_uid';
  $handler->display->display_options['relationships']['field_speakers_uid']['label'] = 'Speaker(s)';
  $handler->display->display_options['relationships']['field_speakers_uid']['required'] = 1;
  $handler->display->display_options['relationships']['field_speakers_uid']['delta'] = '-1';
  /* Relationship: Flags: session_confirm */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['label'] = 'session_confirm';
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'session_confirm';
  $handler->display->display_options['relationships']['flag_content_rel']['user_scope'] = 'any';
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'session' => 'session',
  );
  $handler->display->display_options['filters']['type']['group'] = 0;
  /* Filter criterion: Content: Status (field_accepted) */
  $handler->display->display_options['filters']['field_accepted_value']['id'] = 'field_accepted_value';
  $handler->display->display_options['filters']['field_accepted_value']['table'] = 'field_data_field_accepted';
  $handler->display->display_options['filters']['field_accepted_value']['field'] = 'field_accepted_value';
  $handler->display->display_options['filters']['field_accepted_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_accepted_value']['group'] = 0;
  /* Filter criterion: Content: Room (field_session_room) */
  $handler->display->display_options['filters']['field_session_room_nid']['id'] = 'field_session_room_nid';
  $handler->display->display_options['filters']['field_session_room_nid']['table'] = 'field_data_field_session_room';
  $handler->display->display_options['filters']['field_session_room_nid']['field'] = 'field_session_room_nid';
  $handler->display->display_options['filters']['field_session_room_nid']['operator'] = 'not empty';
  /* Filter criterion: Content: Time slot (field_session_slot) */
  $handler->display->display_options['filters']['field_session_slot_nid']['id'] = 'field_session_slot_nid';
  $handler->display->display_options['filters']['field_session_slot_nid']['table'] = 'field_data_field_session_slot';
  $handler->display->display_options['filters']['field_session_slot_nid']['field'] = 'field_session_slot_nid';
  $handler->display->display_options['filters']['field_session_slot_nid']['operator'] = 'not empty';
  $handler->display->display_options['path'] = 'conference-admin/contact-speakers/confirmed';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Confirmed';
  $handler->display->display_options['menu']['description'] = 'Email speakers who have confirmed for their session';
  $handler->display->display_options['menu']['weight'] = '-5';
  $handler->display->display_options['menu']['name'] = 'menu-menu-conference-admin';
  $export['sessions_admin_contact'] = $view;

  $view = new view;
  $view->name = 'sessions_speaker_confirmation';
  $view->description = 'Your sessions';
  $view->tag = 'cod session';
  $view->base_table = 'node';
  $view->human_name = '';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Speaker confirmation';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = '';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_session_slot' => 'field_session_slot',
    'ops' => 'ops',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_session_slot' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'ops' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  /* Relationship: Flags: session_confirm */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['required'] = 0;
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'session_confirm';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Time slot */
  $handler->display->display_options['fields']['field_session_slot']['id'] = 'field_session_slot';
  $handler->display->display_options['fields']['field_session_slot']['table'] = 'field_data_field_session_slot';
  $handler->display->display_options['fields']['field_session_slot']['field'] = 'field_session_slot';
  $handler->display->display_options['fields']['field_session_slot']['label'] = 'Session date & time';
  $handler->display->display_options['fields']['field_session_slot']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_session_slot']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_session_slot']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_session_slot']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_session_slot']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_session_slot']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_session_slot']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_session_slot']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_session_slot']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_session_slot']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_session_slot']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_session_slot']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_session_slot']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_session_slot']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_session_slot']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_session_slot']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_session_slot']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_session_slot']['field_api_classes'] = 0;
  /* Field: Flags: Flag link */
  $handler->display->display_options['fields']['ops']['id'] = 'ops';
  $handler->display->display_options['fields']['ops']['table'] = 'flag_content';
  $handler->display->display_options['fields']['ops']['field'] = 'ops';
  $handler->display->display_options['fields']['ops']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['ops']['label'] = 'Confirmation';
  $handler->display->display_options['fields']['ops']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['external'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['ops']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['ops']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['ops']['alter']['html'] = 0;
  $handler->display->display_options['fields']['ops']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['ops']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['ops']['empty'] = 'Confirmed';
  $handler->display->display_options['fields']['ops']['hide_empty'] = 0;
  $handler->display->display_options['fields']['ops']['empty_zero'] = 0;
  $handler->display->display_options['fields']['ops']['hide_alter_empty'] = 0;
  /* Contextual filter: Content: Speaker(s) (field_speakers) */
  $handler->display->display_options['arguments']['field_speakers_uid']['id'] = 'field_speakers_uid';
  $handler->display->display_options['arguments']['field_speakers_uid']['table'] = 'field_data_field_speakers';
  $handler->display->display_options['arguments']['field_speakers_uid']['field'] = 'field_speakers_uid';
  $handler->display->display_options['arguments']['field_speakers_uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_speakers_uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['field_speakers_uid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_speakers_uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_speakers_uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_speakers_uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_speakers_uid']['specify_validation'] = 1;
  $handler->display->display_options['arguments']['field_speakers_uid']['validate']['type'] = 'user';
  $handler->display->display_options['arguments']['field_speakers_uid']['validate_options']['type'] = 'either';
  $handler->display->display_options['arguments']['field_speakers_uid']['validate_options']['restrict_roles'] = 0;
  $handler->display->display_options['arguments']['field_speakers_uid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['field_speakers_uid']['not'] = 0;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
  );
  /* Filter criterion: Content: Status (field_accepted) */
  $handler->display->display_options['filters']['field_accepted_value']['id'] = 'field_accepted_value';
  $handler->display->display_options['filters']['field_accepted_value']['table'] = 'field_data_field_accepted';
  $handler->display->display_options['filters']['field_accepted_value']['field'] = 'field_accepted_value';
  $handler->display->display_options['filters']['field_accepted_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_accepted_value']['group'] = 1;
  /* Filter criterion: Content: Room (field_session_room) */
  $handler->display->display_options['filters']['field_session_room_nid']['id'] = 'field_session_room_nid';
  $handler->display->display_options['filters']['field_session_room_nid']['table'] = 'field_data_field_session_room';
  $handler->display->display_options['filters']['field_session_room_nid']['field'] = 'field_session_room_nid';
  $handler->display->display_options['filters']['field_session_room_nid']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_session_room_nid']['group'] = 1;
  /* Filter criterion: Content: Time slot (field_session_slot) */
  $handler->display->display_options['filters']['field_session_slot_nid']['id'] = 'field_session_slot_nid';
  $handler->display->display_options['filters']['field_session_slot_nid']['table'] = 'field_data_field_session_slot';
  $handler->display->display_options['filters']['field_session_slot_nid']['field'] = 'field_session_slot_nid';
  $handler->display->display_options['filters']['field_session_slot_nid']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_session_slot_nid']['group'] = 1;

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');
  $export['sessions_speaker_confirmation'] = $view;

  return $export;
}
