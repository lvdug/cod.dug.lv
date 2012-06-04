<?php

/**
 * Implementation of hook_uuid_features_default_content().
 */
function interest_survey_uuid_features_default_content() {
  $nodes = array();

  $nodes[] = array(
  'type' => 'webform',
  'language' => '',
  'uid' => '1',
  'status' => '1',
  'created' => '1338783163',
  'changed' => '1338832668',
  'comment' => '2',
  'promote' => '1',
  'moderate' => '0',
  'sticky' => '0',
  'tnid' => '0',
  'translate' => '0',
  'revision_uid' => '1',
  'title' => 'DrupalCamp Las Vegas 2012',
  'body' => 'We\'re pleased to announce that DrupalCamp Las Vegas will be happening Friday and Saturday October 5-6 2012 on the campus of UNLV!

Please use the form below to get on our mailing list until we launch our official DrupalCamp site.

Be sure to express your interest in sponsoring, speaking, or providing training!
',
  'teaser' => 'We\'re pleased to announce that DrupalCamp Las Vegas will be happening Friday and Saturday October 5-6 2012 on the campus of UNLV!

Please use the form below to get on our mailing list until we launch our official DrupalCamp site.

Be sure to express your interest in sponsoring, speaking, or providing training!
',
  'log' => '',
  'revision_timestamp' => '1338832668',
  'format' => '1',
  'name' => 'sysadmin',
  'picture' => '',
  'data' => 'a:0:{}',
  'path' => 'content/drupalcamp-las-vegas-2012',
  'signup' => 0,
  'webform' => array(
    'nid' => '3',
    'confirmation' => '',
    'confirmation_format' => '1',
    'redirect_url' => '<confirmation>',
    'status' => '1',
    'block' => '0',
    'teaser' => '0',
    'allow_draft' => '0',
    'auto_save' => '0',
    'submit_notice' => '1',
    'submit_text' => '',
    'submit_limit' => '-1',
    'submit_interval' => '-1',
    'total_submit_limit' => '-1',
    'total_submit_interval' => '-1',
    'record_exists' => TRUE,
    'roles' => array(
      '0' => '1',
    ),
    'emails' => array(
      '1' => array(
        'nid' => '3',
        'eid' => '1',
        'email' => 'drupal@oadaeh.net',
        'subject' => 'default',
        'from_name' => 'default',
        'from_address' => 'default',
        'template' => 'default',
        'excluded_components' => array(),
        'html' => '0',
        'attachments' => '0',
      ),
    ),
    'components' => array(
      '1' => array(
        'nid' => '3',
        'cid' => '1',
        'form_key' => 'name',
        'name' => 'Name',
        'type' => 'textfield',
        'value' => '',
        'extra' => array(
          'title_display' => 'before',
          'private' => 0,
          'disabled' => 0,
          'unique' => 0,
          'conditional_operator' => '=',
          'width' => '',
          'maxlength' => '',
          'field_prefix' => '',
          'field_suffix' => '',
          'description' => '',
          'attributes' => array(),
          'conditional_component' => '',
          'conditional_values' => '',
        ),
        'mandatory' => '0',
        'pid' => '0',
        'weight' => '0',
        'page_num' => 1,
      ),
      '5' => array(
        'nid' => '3',
        'cid' => '5',
        'form_key' => 'nick',
        'name' => 'Nick',
        'type' => 'textfield',
        'value' => '',
        'extra' => array(
          'description' => 'This may be your IRC name or d.o user name.
',
          'title_display' => 'before',
          'private' => 0,
          'disabled' => 0,
          'unique' => 0,
          'conditional_operator' => '=',
          'width' => '',
          'maxlength' => '',
          'field_prefix' => '',
          'field_suffix' => '',
          'attributes' => array(),
          'conditional_component' => '',
          'conditional_values' => '',
        ),
        'mandatory' => '0',
        'pid' => '0',
        'weight' => '2',
        'page_num' => 1,
      ),
      '3' => array(
        'nid' => '3',
        'cid' => '3',
        'form_key' => 'email_address',
        'name' => 'Email Address',
        'type' => 'email',
        'value' => '',
        'extra' => array(
          'description' => 'You will only receive information from official camp organizers regarding DrupalCamp Las Vegas 2012.
',
          'title_display' => 'before',
          'private' => 0,
          'disabled' => 0,
          'unique' => 0,
          'conditional_operator' => '=',
          'width' => '',
          'attributes' => array(),
          'conditional_component' => '',
          'conditional_values' => '',
        ),
        'mandatory' => '1',
        'pid' => '0',
        'weight' => '3',
        'page_num' => 1,
      ),
      '4' => array(
        'nid' => '3',
        'cid' => '4',
        'form_key' => 'interests',
        'name' => 'Interests',
        'type' => 'select',
        'value' => '',
        'extra' => array(
          'items' => 'organizing|Volunteering to help organize the camp
volunteering|Volunteering the at the camp
sponsoring|Sponsoring
swag|Providing SWAG!
training|Delivering a full day, paid training class
attend_training|Attending a training class
keynote|Giving the keynote
session|Delivering a session talk
attend_sessions|Attending the sessions
',
          'multiple' => 1,
          'title_display' => 'before',
          'private' => 0,
          'aslist' => 0,
          'optrand' => 0,
          'conditional_operator' => '=',
          'other_option' => NULL,
          'other_text' => 'Other...',
          'description' => '',
          'custom_keys' => FALSE,
          'options_source' => '',
          'conditional_component' => '',
          'conditional_values' => '',
        ),
        'mandatory' => '1',
        'pid' => '0',
        'weight' => '4',
        'page_num' => 1,
      ),
      '6' => array(
        'nid' => '3',
        'cid' => '6',
        'form_key' => 'other_interest',
        'name' => 'Other Interest',
        'type' => 'textfield',
        'value' => '',
        'extra' => array(
          'description' => 'If there\'s some other aspect of the DrupalCamp you\'re interested in, indicate that here.
',
          'title_display' => 'before',
          'private' => 0,
          'disabled' => 0,
          'unique' => 0,
          'conditional_operator' => '=',
          'width' => '',
          'maxlength' => '',
          'field_prefix' => '',
          'field_suffix' => '',
          'attributes' => array(),
          'conditional_component' => '',
          'conditional_values' => '',
        ),
        'mandatory' => '0',
        'pid' => '0',
        'weight' => '5',
        'page_num' => 1,
      ),
    ),
  ),
  'last_comment_timestamp' => '1338783163',
  'last_comment_name' => NULL,
  'comment_count' => '0',
  'taxonomy' => array(),
  'uuid' => 'cb8ab5e4-ae6e-11e1-8b41-1c7508d515d2',
  'revision_uuid' => '',
  'pathauto_perform_alias' => FALSE,
  'date' => '2012-06-03 21:12:43 -0700',
);
  return $nodes;
}
