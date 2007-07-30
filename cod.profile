<?php // $Id:

/**
 * Return an array of the modules to be enabled when this profile is installed.
 *
 * @return
 *  An array of modules to be enabled.
 */

function cod_profile_modules() {
  return array(

    /* CCK */
    'content', 'content_copy', 'date', 'date_copy', 'fieldgroup', 'imagefield', 'link', 'nodereference', 'number', 'optionwidgets', 'text', 'userreference', 

    /* Conference Organizing */
    'conference_organizing', 

    /* Core - optional */
    'color', 'comment', 'contact', 'help', 'menu', 'path', 'search', 'taxonomy', 'upload', 

    /* Core - required */
    'block', 'filter', 'node', 'system', 'user', 'watchdog', 

    /* Javascript tools */
    'jscalendar', 'jstools', 'tabs', 

    /* Location */
    'location', 

    /* Organic groups */
    'og', 

    /* Other */
    'akismet', 'bio', 'chatroom', 'date_api', 'logintoboggan', 'moduleweight', 'pathauto', 'pearwiki_filter', 'update_status', 'webform', 'wikitools', 

    /* Taxonomy */
    'tagadelic', 

    /* Views */
    'tagadelic_views', 'views', 'views_bonus', 'views_fastsearch', 'views_rss', 'views_theme_wizard', 'views_ui', 

    /* Voting */
    'vote_up_down', 'votingapi', 
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
    'name' => t('Conference Organizing'),
    'description' => t('Select this profile to get a Drupal based conference website.'),
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
  
  // Theme Install
  // --------
  install_default_theme('cod_organizing'); // Theme Stuff
  install_admin_theme('garland'); // Theme Stuff

  // Block Install
  // --------
  global $theme_key;
  $theme_key = "cod_organizing";
  _block_rehash();
  db_query("update blocks set region = '' where theme = '$theme_key' and (module = 'og' or module = 'user' or module = 'menu')");
  
  // CCK Install
  // --------
  $types = array (
    'bio' => 
    array (
      'type' => 'bio',
      'name' => 'Profile',
      'module' => 'node',
      'description' => 'Biography of a conference registrant.',
      'help' => '',
      'has_title' => '1',
      'title_label' => 'Title',
      'has_body' => '1',
      'body_label' => 'Biography',
      'min_word_count' => '0',
      'custom' => '1',
      'modified' => '1',
      'locked' => '0',
      'orig_type' => 'bio',
    ),
    'chatroom' => 
    array (
      'name' => 'Chat room',
      'module' => 'chatroom',
      'description' => 'A chat room provides access to chats and chat archives.',
      'type' => 'chatroom',
      'has_title' => true,
      'title_label' => 'Title',
      'has_body' => true,
      'body_label' => 'Body',
      'custom' => false,
      'modified' => false,
      'locked' => true,
      'orig_type' => 'chatroom',
      'is_new' => true,
    ),
  'webform' => 
    array (
      'type' => 'webform',
      'name' => 'Conference',
      'module' => 'webform',
      'description' => 'Create a conference to publicize on your website.',
      'help' => '',
      'has_title' => '1',
      'title_label' => 'Title',
      'has_body' => '1',
      'body_label' => 'Overview',
      'min_word_count' => '10',
      'custom' => '0',
      'modified' => '1',
      'locked' => '1',
      'orig_type' => 'webform',
    ),
  'discussion' => 
    array (
      'type' => 'discussion',
      'name' => 'Discussions',
      'module' => 'node',
      'description' => 'Items of discussion',
      'help' => '',
      'has_title' => '1',
      'title_label' => 'Topic',
      'has_body' => '1',
      'body_label' => 'Discussion',
      'min_word_count' => '0',
      'custom' => '1',
      'modified' => '1',
      'locked' => '0',
      'orig_type' => '',
    ),
  'link' => 
    array (
      'type' => 'link',
      'name' => 'Links',
      'module' => 'node',
      'description' => 'An user submitted link',
      'help' => '',
      'has_title' => '1',
      'title_label' => 'Link Title',
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'custom' => '1',
      'modified' => '1',
      'locked' => '0',
      'orig_type' => '',
    ),
  'notes' => 
    array (
      'type' => 'notes',
      'name' => 'Wiki Notes',
      'module' => 'node',
      'description' => 'This is a wiki-style page anyone members can modify',
      'help' => '',
      'has_title' => '1',
      'title_label' => 'Title',
      'has_body' => '1',
      'body_label' => 'Body',
      'min_word_count' => '0',
      'custom' => '1',
      'modified' => '1',
      'locked' => '0',
      'orig_type' => '',
    ),
  'page' => 
    array (
      'type' => 'page',
      'name' => 'Page',
      'module' => 'node',
      'description' => 'If you want to add a static page, like a contact page or an about page, use a page.',
      'help' => '',
      'has_title' => '1',
      'title_label' => 'Title',
      'has_body' => '1',
      'body_label' => 'Body',
      'min_word_count' => '0',
      'custom' => '1',
      'modified' => '1',
      'locked' => '0',
      'orig_type' => 'page',
    ),
  'session' => 
    array (
      'type' => 'session',
      'name' => 'Session',
      'module' => 'node',
      'description' => 'Conference session',
      'help' => '',
      'has_title' => '1',
      'title_label' => 'Title',
      'has_body' => '1',
      'body_label' => 'Description',
      'min_word_count' => '0',
      'custom' => '1',
      'modified' => '1',
      'locked' => '0',
      'orig_type' => '',
    ),
  );

  foreach ($types as $content_type) {
    $obj = (object)_node_type_set_defaults($content_type);
    node_type_save($obj);
  }

  include_once('./'. drupal_get_path('module', 'node') .'/content_types.inc'); 
  include_once('./'. drupal_get_path('module', 'content') .'/content_admin.inc');
$types = array(
  'webform' => 'conference.txt',
  'bio' => 'profile.txt',
  'discussion' => 'discussion.txt',
  'link' => 'link.txt',
  'session' => 'session.txt',
);
foreach ($types as $name => $file) {
  $values = array();
  $values['type_name'] = $name;
  $values['macro'] = implode("\n", file(dirname(__file__)."/cck/$file"));
  drupal_execute("content_copy_import_form", $values);
}
   
  // Users Install
  // --------
  install_set_permissions(
    install_add_role('administrator'), array (
      0 => 'administer blocks',
      1 => ' use PHP for block visibility',
      2 => ' access chat rooms',
      3 => ' administer chat rooms',
      4 => ' administer chats',
      5 => ' create chat rooms',
      6 => ' create chats',
      7 => ' edit own chat rooms',
      8 => ' view code review',
      9 => ' view code review all',
      10 => ' access comments',
      11 => ' administer comments',
      12 => ' post comments',
      13 => ' post comments without approval',
      14 => ' switch users',
      15 => ' administer filters',
      16 => ' access links statistics',
      17 => ' submit latitude/longitude',
      18 => ' administer menu',
      19 => ' access content',
      20 => ' administer content types',
      21 => ' administer nodes',
      22 => ' create bio content',
      23 => ' create discussion content',
      24 => ' create link content',
      25 => ' create notes content',
      26 => ' create page content',
      27 => ' create session content',
      28 => ' edit bio content',
      29 => ' edit discussion content',
      30 => ' edit link content',
      31 => ' edit notes content',
      32 => ' edit own bio content',
      33 => ' edit own discussion content',
      34 => ' edit own link content',
      35 => ' edit own notes content',
      36 => ' edit own page content',
      37 => ' edit own session content',
      38 => ' edit page content',
      39 => ' edit session content',
      40 => ' revert revisions',
      41 => ' view revisions',
      42 => ' administer organic groups',
      43 => ' administer url aliases',
      44 => ' create url aliases',
      45 => ' administer pathauto',
      46 => ' access administration pages',
      47 => ' administer site configuration',
      48 => ' select different theme',
      49 => ' administer taxonomy',
      50 => ' upload files',
      51 => ' view uploaded files',
      52 => ' access user profiles',
      53 => ' administer access control',
      54 => ' administer users',
      55 => ' access all views',
      56 => ' administer views',
      57 => ' access up-down vote statistic',
      58 => ' administer up-down vote',
      59 => ' use up-down vote',
      60 => ' view up-down vote',
      61 => ' administer voting api',
      62 => ' access webform results',
      63 => ' clear webform results',
      64 => ' create webforms',
      65 => ' edit own webforms',
      66 => ' edit webforms',
      67 => ' use PHP for additional processing')
      );

      install_set_permissions(1, array (
          0 => 'access content',
          1 => ' view up-down vote')
      );

      install_set_permissions(2, array (
          0 => 'access chat rooms',
          1 => ' access comments',
          2 => ' post comments',
          3 => ' post comments without approval',
          4 => ' access content',
          5 => ' create bio content',
          6 => ' create discussion content',
          7 => ' create link content',
          8 => ' create notes content',
          9 => ' create session content',
          10 => ' edit notes content',
          11 => ' edit own bio content',
          12 => ' edit own discussion content',
          13 => ' edit own link content',
          14 => ' edit own notes content',
          15 => ' access user profiles',
          16 => ' use up-down vote',
          17 => ' view up-down vote',
          18 => ' access webform results')
      );

      install_set_permissions(
        install_add_role('conference organizer'), 
        array (
          0 => 'access chat rooms',
          1 => ' access comments',
          2 => ' post comments',
          3 => ' post comments without approval',
          4 => ' access content',
          5 => ' create bio content',
          6 => ' create discussion content',
          7 => ' create link content',
          8 => ' create notes content',
          9 => ' create session content',
          10 => ' edit notes content',
          11 => ' edit own bio content',
          12 => ' edit own link content',
          13 => ' edit own notes content',
          14 => ' edit own session content',
          15 => ' revert revisions',
          16 => ' view revisions',
          17 => ' upload files',
          18 => ' view uploaded files',
          19 => ' access user profiles',
          20 => ' use up-down vote',
          21 => ' view up-down vote',
          22 => ' access webform results',
          23 => ' create webforms',
          24 => ' edit own webforms',
          25 => ' edit webforms'
        )
      );


      // Menu Install
      // --------
      $primary_menu_id = 2;

      $item = array();
      $item['pid'] = $primary_menu_id;
      $item['path'] = '<front>';
      $item['title'] = st('Home');
      $item['description'] = st('Front Page');
      $item['weight'] = -6;
      $item['type'] = 118;
      menu_save_item($item); 

      // Taxonomy
      // --------

      // A free tagging vocabulary for categories
      $vocabulary = array(
        'name' => 'Tags',
        'help' => '',
        'relations' => '0',
        'hierarchy' => '1',
        'multiple' => '0',
        'required' => '0',
        'tags' => '1',
        'module' => 'taxonomy',
        'weight' => '0',
        'nodes' => array(
          'discussion' => 'discussion',
          'group' => 'group',
        )
      );
      taxonomy_save_vocabulary($vocabulary);

      // Views 
      // --------
      views_load_cache();

      $view = new stdClass();
      $view->name = 'cod_sessions_links';
      $view->description = 'a list of links associated with a particular session';
      $view->access = array (
      );
      $view->view_args_php = '';
      $view->page = TRUE;
      $view->page_title = '';
      $view->page_header = '';
      $view->page_header_format = '2';
      $view->page_footer = '';
      $view->page_footer_format = '1';
      $view->page_empty = 'No links have been submitted for this session.';
      $view->page_empty_format = '2';
      $view->page_type = 'table';
      $view->url = '';
      $view->use_pager = FALSE;
      $view->nodes_per_page = '6';
      $view->sort = array (
        array (
          'tablename' => 'node',
          'field' => 'created',
          'sortorder' => 'ASC',
          'options' => 'normal',
        ),
      );
$view->argument = array (
  array (
    'type' => 'content: field_related_session',
    'argdefault' => '1',
    'title' => '',
    'options' => '',
    'wildcard' => '',
    'wildcard_substitution' => '',
  ),
);
$view->field = array (
  array (
    'tablename' => 'node_data_field_link',
    'field' => 'field_link_url',
    'label' => '',
    'handler' => 'content_views_field_handler_group',
    'options' => 'default',
  ),
  array (
    'tablename' => 'node',
    'field' => 'delete',
    'label' => '',
    'handler' => 'views_handler_node_delete_destination',
  ),
);
$view->filter = array (
  array (
    'tablename' => 'node',
    'field' => 'type',
    'operator' => 'OR',
    'options' => '',
    'value' => array (
      0 => 'link',
    ),
  ),
  array (
    'tablename' => 'node',
    'field' => 'status',
    'operator' => '=',
    'options' => '',
    'value' => '1',
  ),
);
$view->exposed_filter = array (
);
$view->requires = array(node, node_data_field_link);
$views[$view->name] = $view;
views_sanitize_view($view);
drupal_execute('views_edit_view', array(), $view, '');

$view = new stdClass();
$view->name = 'cod_scheduled_sessions';
$view->description = 'Scheduled Sessions';
$view->access = array (
);
$view->view_args_php = '';
$view->page = TRUE;
$view->page_title = 'Scheduled Sessions';
$view->page_header = '';
$view->page_header_format = '1';
$view->page_footer = '';
$view->page_footer_format = '1';
$view->page_empty = 'No sessions have been scheduled.';
$view->page_empty_format = '1';
$view->page_type = 'teaser';
$view->url = 'scheduled_sessions';
$view->use_pager = FALSE;
$view->nodes_per_page = '0';
$view->sort = array (
  array (
    'tablename' => 'node_data_field_weight',
    'field' => 'field_weight_value',
    'sortorder' => 'DESC',
    'options' => '',
  ),
);
$view->argument = array (
  array (
    'type' => 'gid',
    'argdefault' => '1',
    'title' => '',
    'options' => '',
    'wildcard' => '',
    'wildcard_substitution' => '',
  ),
  array (
    'type' => 'content: field_start',
    'argdefault' => '2',
    'title' => '',
    'options' => 'year',
    'wildcard' => '',
    'wildcard_substitution' => '',
  ),
);
$view->field = array (
  array (
    'tablename' => 'node',
    'field' => 'title',
    'label' => '',
    'handler' => 'views_handler_field_nodelink',
    'options' => 'link',
  ),
  array (
    'tablename' => 'node_data_field_location',
    'field' => 'field_location_value',
    'label' => '',
    'handler' => 'content_views_field_handler_group',
    'options' => 'default',
  ),
  array (
    'tablename' => 'node',
    'field' => 'body',
    'label' => '',
    'handler' => 'views_handler_field_body',
  ),
);
$view->filter = array (
  array (
    'tablename' => 'node',
    'field' => 'type',
    'operator' => 'OR',
    'options' => '',
    'value' => array (
      0 => 'session',
    ),
  ),
  array (
    'tablename' => 'node',
    'field' => 'status',
    'operator' => '=',
    'options' => '',
    'value' => '1',
  ),
  array (
    'tablename' => 'node_data_field_scheduled',
    'field' => 'field_scheduled_value_default',
    'operator' => 'OR',
    'options' => '',
    'value' => array (
      2 => '1',
    ),
  ),
  array (
    'tablename' => 'node_data_field_front_page',
    'field' => 'field_front_page_value_default',
    'operator' => 'OR',
    'options' => '',
    'value' => array (
      3 => '1',
    ),
  ),
  );
$view->exposed_filter = array (
);
$view->requires = array(node_data_field_weight, node, node_data_field_location, node_data_field_scheduled, node_data_field_front_page);
$views[$view->name] = $view;
views_sanitize_view($view);
drupal_execute('views_edit_view', array(), $view, '');

$view = new stdClass();
$view->name = 'cod_all_groups';
$view->description = 'All groups';
$view->access = array (
);
$view->view_args_php = '';
$view->page = TRUE;
$view->page_title = 'Groups directory';
$view->page_header = '';
$view->page_header_format = '2';
$view->page_footer = '';
$view->page_footer_format = '1';
$view->page_empty = 'No groups';
$view->page_empty_format = '1';
$view->page_type = 'table';
$view->url = 'groups';
$view->use_pager = TRUE;
$view->nodes_per_page = '90';
$view->sort = array (
);
$view->argument = array (
  array (
    'type' => 'rss_feed',
    'argdefault' => '2',
    'title' => '',
    'options' => '',
    'wildcard' => '',
    'wildcard_substitution' => '',
  ),
);
$view->field = array (
  array (
    'tablename' => 'node',
    'field' => 'title',
    'label' => 'Group Name',
    'handler' => 'views_handler_field_nodelink',
    'sortable' => '1',
    'options' => 'link',
  ),
  array (
    'tablename' => 'og',
    'field' => 'description',
    'label' => 'Description',
  ),
  array (
    'tablename' => 'og',
    'field' => 'count',
    'label' => 'Number of Members',
  ),
  array (
    'tablename' => 'og',
    'field' => 'subscribe',
    'label' => 'Membership',
  ),
  );
$view->filter = array (
  array (
    'tablename' => 'node',
    'field' => 'distinct',
    'operator' => '=',
    'options' => '',
    'value' => array (
      0 => 'distinct',
    ),
  ),
  array (
    'tablename' => 'node',
    'field' => 'status',
    'operator' => '=',
    'options' => '',
    'value' => '1',
  ),
  array (
    'tablename' => 'node',
    'field' => 'title',
    'operator' => 'contains',
    'options' => '',
    'value' => '\'\'',
  ),
  array (
    'tablename' => 'og_views',
    'field' => 'og_type',
    'operator' => '=',
    'options' => '',
    'value' => '0',
  ),
  array (
    'tablename' => 'og_uid',
    'field' => 'currentuidsimple',
    'operator' => '!=',
    'options' => '',
    'value' => '***CURRENT_USER***',
  ),
  );
$view->exposed_filter = array (
  array (
    'tablename' => 'node',
    'field' => 'title',
    'label' => 'Search for a group by name',
    'optional' => '1',
    'is_default' => '0',
    'operator' => '1',
    'single' => '0',
  ),
);
$view->requires = array(node, og, og_views, og_uid);
$views[$view->name] = $view;
views_sanitize_view($view);
drupal_execute('views_edit_view', array(), $view, '');

$view = new stdClass();
$view->name = 'cod_attendees';
$view->description = 'Attendees';
$view->access = array (
  0 => '3',
);
$view->view_args_php = '';
$view->page = TRUE;
$view->page_title = 'Attendees';
$view->page_header = '';
$view->page_header_format = '1';
$view->page_footer = '';
$view->page_footer_format = '1';
$view->page_empty = '';
$view->page_empty_format = '1';
$view->page_type = 'table';
$view->url = '';
$view->use_pager = TRUE;
$view->nodes_per_page = '10';
$view->sort = array (
);
$view->argument = array (
  array (
    'type' => 'uid',
    'argdefault' => '1',
    'title' => '',
    'options' => '',
    'wildcard' => '',
    'wildcard_substitution' => '',
  ),
);
$view->field = array (
  array (
    'tablename' => 'users',
    'field' => 'uid',
    'label' => '',
  ),
  array (
    'tablename' => 'node_data_field_first_name',
    'field' => 'field_first_name_value',
    'label' => 'First',
    'handler' => 'content_views_field_handler_group',
    'sortable' => '1',
    'options' => 'default',
  ),
  array (
    'tablename' => 'node_data_field_last_name',
    'field' => 'field_last_name_value',
    'label' => 'Last',
    'handler' => 'content_views_field_handler_group',
    'sortable' => '1',
    'options' => 'default',
  ),
  array (
    'tablename' => 'node_data_field_organization',
    'field' => 'field_organization_value',
    'label' => 'Organization',
    'handler' => 'content_views_field_handler_group',
    'sortable' => '1',
    'options' => 'default',
  ),
  array (
    'tablename' => 'node_data_field_title',
    'field' => 'field_title_value',
    'label' => 'Title',
    'handler' => 'content_views_field_handler_group',
    'sortable' => '1',
    'options' => 'default',
  ),
  array (
    'tablename' => 'node',
    'field' => 'view',
    'label' => '',
    'options' => 'View Profile',
  ),
  array (
    'tablename' => 'conference_contact',
    'field' => 'contact',
    'label' => '',
    'options' => 'icon',
  ),
  );
$view->filter = array (
  array (
    'tablename' => 'node',
    'field' => 'type',
    'operator' => 'OR',
    'options' => '',
    'value' => array (
      0 => 'bio',
    ),
  ),
  array (
    'tablename' => 'temp_search_results',
    'field' => 'word',
    'operator' => '=',
    'options' => '',
    'value' => '',
  ),
  array (
    'tablename' => 'search_index',
    'field' => 'word',
    'operator' => '=',
    'options' => '',
    'value' => '',
  ),
  );
$view->exposed_filter = array (
  array (
    'tablename' => 'search_index',
    'field' => 'word',
    'label' => 'Search Attendees',
    'optional' => '1',
    'is_default' => '0',
    'operator' => '1',
    'single' => '1',
  ),
);
$view->requires = array(users, node_data_field_first_name, node_data_field_last_name, node_data_field_organization, node_data_field_title, node, conference_contact, temp_search_results, search_index);
$views[$view->name] = $view;
views_sanitize_view($view);
drupal_execute('views_edit_view', array(), $view, '');

$view = new stdClass();
$view->name = 'cod_discussions';
$view->description = 'Recent Discussions';
$view->access = array (
);
$view->view_args_php = '';
$view->page = TRUE;
$view->page_title = 'Discussions';
$view->page_header = '<p>
<?php
$group = conference_organizing_get_conference_context();
print l(\'Start a Discussion\',\'node/add/discussion/parent/\'.$group->nid);
?>
</p>';
$view->page_header_format = '2';
$view->page_footer = '';
$view->page_footer_format = '1';
$view->page_empty = '<p>
<?php
$group = conference_organizing_get_conference_context();
print l(\'Start a Discussion\',\'node/add/discussion/parent/\'.$group->nid);
?>
</p>
<p>No Discussions Found</p>';
$view->page_empty_format = '2';
$view->page_type = 'table';
$view->url = '';
$view->use_pager = TRUE;
$view->nodes_per_page = '10';
$view->sort = array (
  array (
    'tablename' => 'node_comment_statistics',
    'field' => 'last_comment_timestamp',
    'sortorder' => 'DESC',
    'options' => 'normal',
  ),
  array (
    'tablename' => 'node',
    'field' => 'created',
    'sortorder' => 'DESC',
    'options' => 'normal',
  ),
);
$view->argument = array (
  array (
    'type' => 'gid',
    'argdefault' => '1',
    'title' => '',
    'options' => '',
    'wildcard' => '',
    'wildcard_substitution' => '',
  ),
);
$view->field = array (
  array (
    'tablename' => 'node',
    'field' => 'title',
    'label' => 'Topic',
    'handler' => 'views_handler_field_nodelink',
    'options' => 'link',
  ),
  array (
    'tablename' => 'node_data_field_related_session',
    'field' => 'field_related_session_nid',
    'label' => 'Related Session',
    'handler' => 'content_views_field_handler_group',
    'options' => 'default',
  ),
  array (
    'tablename' => 'node_comment_statistics',
    'field' => 'comment_count',
    'label' => 'Comments',
    'handler' => 'views_handler_field_int',
  ),
  array (
    'tablename' => 'node_comment_statistics',
    'field' => 'last_comment_timestamp',
    'label' => 'Last Comment',
    'handler' => 'views_handler_field_date_small',
  ),
  );
$view->filter = array (
  array (
    'tablename' => 'node',
    'field' => 'type',
    'operator' => 'OR',
    'options' => '',
    'value' => array (
      0 => 'discussion',
    ),
  ),
  array (
    'tablename' => 'node',
    'field' => 'status',
    'operator' => '=',
    'options' => '',
    'value' => '1',
  ),
);
$view->exposed_filter = array (
);
$view->requires = array(node_comment_statistics, node, node_data_field_related_session);
$views[$view->name] = $view;
views_sanitize_view($view);
drupal_execute('views_edit_view', array(), $view, '');

$view = new stdClass();
$view->name = 'cod_discussions_block';
$view->description = 'Conference Discussion';
$view->access = array (
);
$view->view_args_php = '';
$view->block = TRUE;
$view->block_title = 'Conference Discussion';
$view->block_header = '';
$view->block_header_format = '1';
$view->block_footer = '';
$view->block_footer_format = '1';
$view->block_empty = '';
$view->block_empty_format = '1';
$view->block_type = 'teaser';
$view->nodes_per_block = '3';
$view->block_more = TRUE;
$view->block_use_page_header = FALSE;
$view->block_use_page_footer = FALSE;
$view->block_use_page_empty = FALSE;
$view->sort = array (
  array (
    'tablename' => 'node',
    'field' => 'created',
    'sortorder' => 'DESC',
    'options' => 'normal',
  ),
  array (
    'tablename' => 'comments',
    'field' => 'timestamp',
    'sortorder' => 'DESC',
    'options' => 'normal',
  ),
);
$view->argument = array (
  array (
    'type' => 'gid',
    'argdefault' => '1',
    'title' => '',
    'options' => '',
    'wildcard' => '',
    'wildcard_substitution' => '',
  ),
);
$view->field = array (
);
$view->filter = array (
  array (
    'tablename' => 'node',
    'field' => 'status',
    'operator' => '=',
    'options' => '',
    'value' => '1',
  ),
  array (
    'tablename' => 'node',
    'field' => 'type',
    'operator' => 'OR',
    'options' => '',
    'value' => array (
      0 => 'discussion',
    ),
  ),
  array (
    'tablename' => 'node',
    'field' => 'distinct',
    'operator' => '=',
    'options' => '',
    'value' => array (
      0 => 'distinct',
    ),
  ),
  );
$view->exposed_filter = array (
);
$view->requires = array(node, comments);
$views[$view->name] = $view;

views_sanitize_view($view);
drupal_execute('views_edit_view', array(), $view, '');

$view = new stdClass();
$view->name = 'cod_group_tags';
$view->description = 'Group tag cloud';
$view->access = array (
);
$view->view_args_php = '';
$view->page = TRUE;
$view->page_title = '';
$view->page_header = '';
$view->page_header_format = '1';
$view->page_footer = '';
$view->page_footer_format = '1';
$view->page_empty = '';
$view->page_empty_format = '1';
$view->page_type = 'tagadelic';
$view->url = 'group_tags';
$view->use_pager = TRUE;
$view->nodes_per_page = '10';
$view->sort = array (
);
$view->argument = array (
  array (
    'type' => 'gid',
    'argdefault' => '1',
    'title' => '',
    'options' => '',
    'wildcard' => '',
    'wildcard_substitution' => '',
  ),
);
$view->field = array (
  array (
    'tablename' => 'term_node_2',
    'field' => 'name',
    'label' => '',
    'options' => 'link',
  ),
);
$view->filter = array (
);
$view->exposed_filter = array (
);
$view->requires = array(term_node_2);
$views[$view->name] = $view;
views_sanitize_view($view);
drupal_execute('views_edit_view', array(), $view, '');

$view = new stdClass();
$view->name = 'cod_my_schedule';
$view->description = 'My Schedule';
$view->access = array (
);
$view->view_args_php = '';
$view->page = TRUE;
$view->page_title = '';
$view->page_header = '';
$view->page_header_format = '2';
$view->page_footer = '';
$view->page_footer_format = '1';
$view->page_empty = 'No signups have been found for these sessions.';
$view->page_empty_format = '1';
$view->page_type = 'schedule_list';
$view->url = '';
$view->use_pager = FALSE;
$view->nodes_per_page = '0';
$view->sort = array (
  array (
    'tablename' => 'node_data_field_schedule_start_time',
    'field' => 'field_schedule_start_time_value',
    'sortorder' => 'ASC',
    'options' => '',
  ),
);
$view->argument = array (
  array (
    'type' => 'gid',
    'argdefault' => '1',
    'title' => '',
    'options' => '',
    'wildcard' => '',
    'wildcard_substitution' => '',
  ),
  array (
    'type' => 'content: field_attending',
    'argdefault' => '1',
    'title' => '',
    'options' => '',
    'wildcard' => '',
    'wildcard_substitution' => '',
  ),
  array (
    'type' => 'content: field_schedule_start_time',
    'argdefault' => '2',
    'title' => '',
    'options' => 'year',
    'wildcard' => '',
    'wildcard_substitution' => '',
  ),
  );
$view->field = array (
  array (
    'tablename' => 'node_data_field_schedule_start_time',
    'field' => 'field_schedule_start_time_value',
    'label' => '',
    'handler' => 'content_views_field_handler_group',
    'options' => 'default',
  ),
  array (
    'tablename' => 'node_data_field_session_end_time',
    'field' => 'field_session_end_time_value',
    'label' => '',
    'handler' => 'content_views_field_handler_group',
    'options' => 'default',
  ),
  array (
    'tablename' => 'node_data_field_track',
    'field' => 'field_track_value',
    'label' => '',
    'handler' => 'content_views_field_handler_group',
    'options' => 'default',
  ),
  array (
    'tablename' => 'node',
    'field' => 'title',
    'label' => '',
    'handler' => 'views_handler_field_nodelink',
    'options' => 'link',
  ),
  array (
    'tablename' => 'node_data_field_location',
    'field' => 'field_location_value',
    'label' => '',
    'handler' => 'content_views_field_handler_group',
    'options' => 'default',
  ),
  );
$view->filter = array (
  array (
    'tablename' => 'node',
    'field' => 'type',
    'operator' => 'OR',
    'options' => '',
    'value' => array (
      0 => 'session',
    ),
  ),
  array (
    'tablename' => 'node',
    'field' => 'status',
    'operator' => '=',
    'options' => '',
    'value' => '1',
  ),
  array (
    'tablename' => 'node_data_field_scheduled',
    'field' => 'field_scheduled_value_default',
    'operator' => 'OR',
    'options' => '',
    'value' => array (
      0 => '1',
    ),
  ),
  );
$view->exposed_filter = array (
);
$view->requires = array(node_data_field_schedule_start_time, node_data_field_session_end_time, node_data_field_track, node, node_data_field_location, node_data_field_scheduled);
$views[$view->name] = $view;
views_sanitize_view($view);
drupal_execute('views_edit_view', array(), $view, '');

$view = new stdClass();
$view->name = 'cod_proposed_sessions';
$view->description = 'Proposed Sessions';
$view->access = array (
);
$view->view_args_php = '';
$view->page = TRUE;
$view->page_title = 'Proposed Sessions';
$view->page_header = '';
$view->page_header_format = '2';
$view->page_footer = '';
$view->page_footer_format = '1';
$view->page_empty = 'No proposed sessions have been found.';
$view->page_empty_format = '1';
$view->page_type = 'teaser';
$view->url = 'proposed_sessions';
$view->use_pager = TRUE;
$view->nodes_per_page = '5';
$view->sort = array (
);
$view->argument = array (
  array (
    'type' => 'gid',
    'argdefault' => '1',
    'title' => '',
    'options' => '',
    'wildcard' => '',
    'wildcard_substitution' => '',
  ),
  array (
    'type' => 'content: field_start',
    'argdefault' => '2',
    'title' => '',
    'options' => 'year',
    'wildcard' => '',
    'wildcard_substitution' => '',
  ),
);
$view->field = array (
);
$view->filter = array (
  array (
    'tablename' => 'node',
    'field' => 'type',
    'operator' => 'OR',
    'options' => '',
    'value' => array (
      0 => 'session',
    ),
  ),
  array (
    'tablename' => 'node',
    'field' => 'status',
    'operator' => '=',
    'options' => '',
    'value' => '1',
  ),
  array (
    'tablename' => 'node_data_field_scheduled',
    'field' => 'field_scheduled_value_default',
    'operator' => 'NOR',
    'options' => '',
    'value' => array (
      0 => '1',
    ),
  ),
  );
$view->exposed_filter = array (
);
$view->requires = array(node, node_data_field_scheduled);
$views[$view->name] = $view;
views_sanitize_view($view);
drupal_execute('views_edit_view', array(), $view, '');

$view = new stdClass();
$view->name = 'cod_schedule';
$view->description = 'Schedule';
$view->access = array (
);
$view->view_args_php = '';
$view->page = TRUE;
$view->page_title = 'Schedule';
$view->page_header = '';
$view->page_header_format = '2';
$view->page_footer = '';
$view->page_footer_format = '1';
$view->page_empty = 'No sessions have been scheduled.';
$view->page_empty_format = '1';
$view->page_type = 'schedule_schedule';
$view->url = '';
$view->use_pager = FALSE;
$view->nodes_per_page = '0';
$view->sort = array (
  array (
    'tablename' => 'node_data_field_schedule_start_time',
    'field' => 'field_schedule_start_time_value',
    'sortorder' => 'ASC',
    'options' => '',
  ),
);
$view->argument = array (
  array (
    'type' => 'gid',
    'argdefault' => '1',
    'title' => '',
    'options' => '',
    'wildcard' => '',
    'wildcard_substitution' => '',
  ),
  array (
    'type' => 'content: field_schedule_start_time',
    'argdefault' => '2',
    'title' => '',
    'options' => 'year',
    'wildcard' => '',
    'wildcard_substitution' => '',
  ),
);
$view->field = array (
  array (
    'tablename' => 'node_data_field_schedule_start_time',
    'field' => 'field_schedule_start_time_value',
    'label' => '',
    'handler' => 'content_views_field_handler_group',
    'options' => 'default',
  ),
  array (
    'tablename' => 'node_data_field_session_end_time',
    'field' => 'field_session_end_time_value',
    'label' => '',
    'handler' => 'content_views_field_handler_group',
    'options' => 'default',
  ),
  array (
    'tablename' => 'node_data_field_track',
    'field' => 'field_track_value',
    'label' => '',
    'handler' => 'content_views_field_handler_group',
    'options' => 'default',
  ),
  array (
    'tablename' => 'node',
    'field' => 'title',
    'label' => '',
    'handler' => 'views_handler_field_nodelink',
    'options' => 'link',
  ),
  array (
    'tablename' => 'node_data_field_location',
    'field' => 'field_location_value',
    'label' => '',
    'handler' => 'content_views_field_handler_group',
    'options' => 'default',
  ),
  );
$view->filter = array (
  array (
    'tablename' => 'node',
    'field' => 'type',
    'operator' => 'OR',
    'options' => '',
    'value' => array (
      0 => 'session',
    ),
  ),
  array (
    'tablename' => 'node',
    'field' => 'status',
    'operator' => '=',
    'options' => '',
    'value' => '1',
  ),
  array (
    'tablename' => 'node_data_field_scheduled',
    'field' => 'field_scheduled_value_default',
    'operator' => 'OR',
    'options' => '',
    'value' => array (
      0 => '1',
    ),
  ),
  );
$view->exposed_filter = array (
);
$view->requires = array(node_data_field_schedule_start_time, node_data_field_session_end_time, node_data_field_track, node, node_data_field_location, node_data_field_scheduled);
$views[$view->name] = $view;
views_sanitize_view($view);
drupal_execute('views_edit_view', array(), $view, '');

$view = new stdClass();
$view->name = 'cod_conferences';
$view->description = 'Conferences';
$view->access = array (
);
$view->view_args_php = '';
$view->page = TRUE;
$view->page_title = 'Conferences';
$view->page_header = 'Here at CoLab, we are working to provide you with a virtual, interactive conference that will allow you to actively participate in and catalog your discussions pertaining to the various seminars that will be presented. The first step in achieving this goal is to motivate all of you to comment on seminars that you think will be interesting, or anything else that may appeal to you, prior to attending the summit. An earlier email has already been sent informing you of your username and password. Once you login with these, please take a minute to fill out your profile and change your password, before proceeding to the Summit website. During your exploration of our site, please feel free to comment on any of the seminars. Thanks so much for your participation and feedback. 
';
$view->page_header_format = '4';
$view->page_footer = '<?php
$view = views_get_view(\'cod_conferences_past\');
$view = views_build_view(\'embed\', $view, array(), NULL, NULL);
$output = \'<h2>Past Conferences</h2>\';
$output .= $view;
echo $output;
?>';
$view->page_footer_format = '2';
$view->page_empty = '';
$view->page_empty_format = '4';
$view->page_type = 'table';
$view->url = 'conferences';
$view->use_pager = TRUE;
$view->nodes_per_page = '5';
$view->menu = TRUE;
$view->menu_title = 'Conferences';
$view->menu_tab = FALSE;
$view->menu_tab_weight = '0';
$view->menu_tab_default = FALSE;
$view->menu_tab_default_parent = NULL;
$view->menu_parent_tab_weight = '0';
$view->menu_parent_title = '';
$view->sort = array (
  array (
    'tablename' => 'node_data_field_start',
    'field' => 'field_start_value',
    'sortorder' => 'DESC',
    'options' => '',
  ),
);
$view->argument = array (
);
$view->field = array (
  array (
    'tablename' => 'node_data_field_cod_logo',
    'field' => 'field_cod_logo_fid',
    'label' => 'Logo',
    'handler' => 'content_views_field_handler_group',
    'options' => 'default',
  ),
  array (
    'tablename' => 'node',
    'field' => 'title',
    'label' => 'Title',
    'handler' => 'views_handler_field_nodelink',
    'options' => 'link',
  ),
  array (
    'tablename' => 'node_data_field_start',
    'field' => 'field_start_value',
    'label' => 'Start',
    'handler' => 'content_views_field_handler_group',
    'options' => 'default',
  ),
  array (
    'tablename' => 'node_data_field_end',
    'field' => 'field_end_value',
    'label' => 'End',
    'handler' => 'content_views_field_handler_group',
    'options' => 'default',
  ),
  );
$view->filter = array (
  array (
    'tablename' => 'node',
    'field' => 'type',
    'operator' => 'OR',
    'options' => '',
    'value' => array (
      0 => 'webform',
    ),
  ),
  array (
    'tablename' => 'node_data_field_end',
    'field' => 'field_end_value_default',
    'operator' => '>=',
    'options' => '',
    'value' => 'now',
  ),
);
$view->exposed_filter = array (
);
$view->requires = array(node_data_field_start, node_data_field_cod_logo, node, node_data_field_end);
$views[$view->name] = $view;
views_sanitize_view($view);
drupal_execute('views_edit_view', array(), $view, '');

$view = new stdClass();
$view->name = 'cod_home';
$view->description = 'Home';
$view->access = array (
);
$view->view_args_php = '';
$view->page = TRUE;
$view->page_title = 'Home';
$view->page_header = '';
$view->page_header_format = '4';
$view->page_footer = '';
$view->page_footer_format = '4';
$view->page_empty = '';
$view->page_empty_format = '4';
$view->page_type = 'node';
$view->url = '';
$view->use_pager = FALSE;
$view->nodes_per_page = '1';
$view->sort = array (
  array (
    'tablename' => 'node_data_field_end',
    'field' => 'field_end_value',
    'sortorder' => 'DESC',
    'options' => '',
  ),
);
$view->argument = array (
);
$view->field = array (
);
$view->filter = array (
  array (
    'tablename' => 'node',
    'field' => 'type',
    'operator' => 'OR',
    'options' => '',
    'value' => array (
      0 => 'webform',
    ),
  ),
  array (
    'tablename' => 'node',
    'field' => 'status',
    'operator' => '=',
    'options' => '',
    'value' => '1',
  ),
  array (
    'tablename' => 'node_data_field_end',
    'field' => 'field_end_value_default',
    'operator' => '>=',
    'options' => '',
    'value' => 'now',
  ),
  );
$view->exposed_filter = array (
);
$view->requires = array(node_data_field_end, node);
$views[$view->name] = $view;
views_sanitize_view($view);
drupal_execute('views_edit_view', array(), $view, '');

$view = new stdClass();
$view->name = 'cod_members';
$view->description = 'Members';
$view->access = array (
  0 => '3',
);
$view->view_args_php = '';
$view->page = TRUE;
$view->page_title = 'Members';
$view->page_header = '';
$view->page_header_format = '1';
$view->page_footer = '';
$view->page_footer_format = '1';
$view->page_empty = '';
$view->page_empty_format = '1';
$view->page_type = 'table';
$view->url = '';
$view->use_pager = TRUE;
$view->nodes_per_page = '10';
$view->sort = array (
);
$view->argument = array (
  array (
    'type' => 'uid',
    'argdefault' => '1',
    'title' => '',
    'options' => '',
    'wildcard' => '',
    'wildcard_substitution' => '',
  ),
);
$view->field = array (
  array (
    'tablename' => 'users',
    'field' => 'uid',
    'label' => '',
  ),
  array (
    'tablename' => 'node_data_field_first_name',
    'field' => 'field_first_name_value',
    'label' => 'First',
    'handler' => 'content_views_field_handler_group',
    'sortable' => '1',
    'options' => 'default',
  ),
  array (
    'tablename' => 'node_data_field_last_name',
    'field' => 'field_last_name_value',
    'label' => 'Last',
    'handler' => 'content_views_field_handler_group',
    'sortable' => '1',
    'options' => 'default',
  ),
  array (
    'tablename' => 'node_data_field_organization',
    'field' => 'field_organization_value',
    'label' => 'Organization',
    'handler' => 'content_views_field_handler_group',
    'sortable' => '1',
    'options' => 'default',
  ),
  array (
    'tablename' => 'node_data_field_title',
    'field' => 'field_title_value',
    'label' => 'Title',
    'handler' => 'content_views_field_handler_group',
    'sortable' => '1',
    'options' => 'default',
  ),
  array (
    'tablename' => 'node',
    'field' => 'view',
    'label' => '',
    'options' => 'View Profile',
  ),
  array (
    'tablename' => 'conference_contact',
    'field' => 'contact',
    'label' => '',
    'options' => 'icon',
  ),
  );
$view->filter = array (
  array (
    'tablename' => 'node',
    'field' => 'type',
    'operator' => 'OR',
    'options' => '',
    'value' => array (
      0 => 'bio',
    ),
  ),
  array (
    'tablename' => 'temp_search_results',
    'field' => 'word',
    'operator' => '=',
    'options' => '',
    'value' => '',
  ),
  array (
    'tablename' => 'search_index',
    'field' => 'word',
    'operator' => '=',
    'options' => '',
    'value' => '',
  ),
  );
$view->exposed_filter = array (
  array (
    'tablename' => 'search_index',
    'field' => 'word',
    'label' => 'Search members',
    'optional' => '1',
    'is_default' => '0',
    'operator' => '1',
    'single' => '1',
  ),
);
$view->requires = array(users, node_data_field_first_name, node_data_field_last_name, node_data_field_organization, node_data_field_title, node, conference_contact, temp_search_results, search_index);
$views[$view->name] = $view;
views_sanitize_view($view);
drupal_execute('views_edit_view', array(), $view, '');

$view = new stdClass();
$view->name = 'cod_conferences_past';
$view->description = 'Conferences';
$view->access = array (
);
$view->view_args_php = '';
$view->page = TRUE;
$view->page_title = 'Past Conferences';
$view->page_header = '';
$view->page_header_format = '4';
$view->page_footer = '';
$view->page_footer_format = '4';
$view->page_empty = '';
$view->page_empty_format = '4';
$view->page_type = 'table';
$view->url = 'conferences/past';
$view->use_pager = TRUE;
$view->nodes_per_page = '5';
$view->menu = TRUE;
$view->menu_title = 'Conferences';
$view->menu_tab = FALSE;
$view->menu_tab_weight = '0';
$view->menu_tab_default = FALSE;
$view->menu_tab_default_parent = NULL;
$view->menu_parent_tab_weight = '0';
$view->menu_parent_title = '';
$view->sort = array (
  array (
    'tablename' => 'node_data_field_start',
    'field' => 'field_start_value',
    'sortorder' => 'DESC',
    'options' => '',
  ),
);
$view->argument = array (
);
$view->field = array (
  array (
    'tablename' => 'node_data_field_cod_logo',
    'field' => 'field_cod_logo_fid',
    'label' => 'Logo',
    'handler' => 'content_views_field_handler_group',
    'options' => 'default',
  ),
  array (
    'tablename' => 'node',
    'field' => 'title',
    'label' => 'Title',
    'handler' => 'views_handler_field_nodelink',
    'options' => 'link',
  ),
  array (
    'tablename' => 'node_data_field_start',
    'field' => 'field_start_value',
    'label' => 'Start',
    'handler' => 'content_views_field_handler_group',
    'options' => 'default',
  ),
  array (
    'tablename' => 'node_data_field_end',
    'field' => 'field_end_value',
    'label' => 'End',
    'handler' => 'content_views_field_handler_group',
    'options' => 'default',
  ),
  );
$view->filter = array (
  array (
    'tablename' => 'node',
    'field' => 'type',
    'operator' => 'OR',
    'options' => '',
    'value' => array (
      0 => 'webform',
    ),
  ),
  array (
    'tablename' => 'node_data_field_end',
    'field' => 'field_end_value_default',
    'operator' => '<',
    'options' => '',
    'value' => 'now',
  ),
);
$view->exposed_filter = array (
);
$view->requires = array(node_data_field_start, node_data_field_cod_logo, node, node_data_field_end);
$views[$view->name] = $view;
views_sanitize_view($view);
drupal_execute('views_edit_view', array(), $view, '');

// Make some Database changes
db_query("update {view_filter} set value = '1' where field = 'node_data_field_scheduled.field_scheduled_value_default';");
db_query("update {view_filter} set value = '1' where field = 'node_data_field_front_page.field_front_page_value_default';");
db_query("update {view_view} set page_empty_format = '2' where name = 'cod_discussions' or name = 'cod_sessions_links';");

  // Variables
  // ---------
variable_set('filter_default_format', '4');

variable_set('admin_theme', 'garland');
variable_set('allowed_html_1', '<a> <em> <i> <u> <b> <strong> <code> <ul> <ol> <li> <dl> <dt> <dd>');
variable_set('anonymous', 'Anonymous');
variable_set('bio_link', array (
    1 => 1,
    0 => 1,
    'bio' => 0,
    'webform' => 0,
    'page' => 0,
    'session' => 0,
));
variable_set('bio_nodetype', 'bio');
variable_set('bio_profile', 1);
variable_set('bio_profile_takeover', 1);
variable_set('chatroom_auto_archive', 1);
variable_set('clean_url', '1');
variable_set('cod_registration_enforcement', 'nudge');
variable_set('color_garland_files', array (
    0 => 'files/color/garland-66a272d3/menu-collapsed.gif',
    1 => 'files/color/garland-66a272d3/menu-expanded.gif',
    2 => 'files/color/garland-66a272d3/menu-leaf.gif',
    3 => 'files/color/garland-66a272d3/body.png',
    4 => 'files/color/garland-66a272d3/bg-bar.png',
    5 => 'files/color/garland-66a272d3/bg-bar-white.png',
    6 => 'files/color/garland-66a272d3/bg-tab.png',
    7 => 'files/color/garland-66a272d3/bg-navigation.png',
    8 => 'files/color/garland-66a272d3/bg-content-left.png',
    9 => 'files/color/garland-66a272d3/bg-content-right.png',
    10 => 'files/color/garland-66a272d3/bg-content.png',
    11 => 'files/color/garland-66a272d3/bg-navigation-item.png',
    12 => 'files/color/garland-66a272d3/bg-navigation-item-hover.png',
    13 => 'files/color/garland-66a272d3/gradient-inner.png',
    14 => 'files/color/garland-66a272d3/logo.png',
    15 => 'files/color/garland-66a272d3/screenshot.png',
    16 => 'files/color/garland-66a272d3/style.css',
));
variable_set('color_garland_logo', 'files/color/garland-66a272d3/logo.png');
variable_set('color_garland_palette', array (
    'base' => '#636363',
    'link' => '#6f6f6f',
    'top' => '#818181',
    'bottom' => '#a7a7a7',
    'text' => '#4e4e4e',
));
variable_set('color_garland_screenshot', 'files/color/garland-66a272d3/screenshot.png');
variable_set('color_garland_stylesheet', 'files/color/garland-66a272d3/style.css');
variable_set('comment_anonymous', 0);
variable_set('comment_bio', '0');
variable_set('comment_conference_og', '2');
variable_set('comment_conference_signup', '2');
variable_set('comment_controls', '3');
variable_set('comment_default_mode', '4');
variable_set('comment_default_order', '1');
variable_set('comment_default_per_page', '50');
variable_set('comment_discussion', '2');
variable_set('comment_form_location', '0');
variable_set('comment_group', '0');
variable_set('comment_link', '0');
variable_set('comment_notes', '2');
variable_set('comment_page', 0);
variable_set('comment_preview', '1');
variable_set('comment_session', '2');
variable_set('comment_subject_field', '1');
variable_set('comment_webform', '2');
variable_set('configurable_timezones', '0');
variable_set('content_schema_version', 1003);
variable_set('cron_last', 1184713501);
variable_set('date_default_timezone', '-25200');
variable_set('date_default_timezone_name', 'America/Los_Angeles');
variable_set('date_first_day', '1');
variable_set('date_format_long', 'l, F j, Y - g:ia');
variable_set('date_format_medium', 'D, m/d/Y - g:ia');
variable_set('date_format_short', 'm/d/Y - g:ia');
variable_set('date_version', '-1');
variable_set('file_directory_temp', '/tmp');
variable_set('filter_html_1', '1');
variable_set('filter_html_help_1', 0);
variable_set('filter_html_nofollow_1', 0);
variable_set('filter_url_length_1', '72');
variable_set('install_profile', 'default');
variable_set('jscalendar_css', 'sites/all/modules/jstools/jscalendar/lib/calendar-win2k-2.css');
variable_set('location_addanother_bio', 0);
variable_set('location_addanother_discussion', 0);
variable_set('location_addanother_group', 0);
variable_set('location_addanother_link', 0);
variable_set('location_addanother_notes', 0);
variable_set('location_addanother_webform', 0);
variable_set('location_city_bio', '1');
variable_set('location_city_discussion', '0');
variable_set('location_city_group', '0');
variable_set('location_city_link', '0');
variable_set('location_city_notes', '0');
variable_set('location_city_webform', '1');
variable_set('location_collapsed_bio', 0);
variable_set('location_collapsed_discussion', 1);
variable_set('location_collapsed_group', 1);
variable_set('location_collapsed_link', 1);
variable_set('location_collapsed_notes', 1);
variable_set('location_collapsed_webform', 0);
variable_set('location_collapsible_bio', 1);
variable_set('location_collapsible_discussion', 1);
variable_set('location_collapsible_group', 1);
variable_set('location_collapsible_link', 1);
variable_set('location_collapsible_notes', 1);
variable_set('location_collapsible_webform', 0);
variable_set('location_country_bio', '1');
variable_set('location_country_discussion', '1');
variable_set('location_country_group', '1');
variable_set('location_country_link', '1');
variable_set('location_country_notes', '1');
variable_set('location_country_webform', '1');
variable_set('location_default_country', 'us');
variable_set('location_defaultnum_bio', '1');
variable_set('location_defaultnum_discussion', '0');
variable_set('location_defaultnum_group', '0');
variable_set('location_defaultnum_link', '0');
variable_set('location_defaultnum_notes', '0');
variable_set('location_defaultnum_webform', '1');
variable_set('location_display_location', '1');
variable_set('location_geocode_us', 'google');
variable_set('location_maxnum_bio', '1');
variable_set('location_maxnum_discussion', '0');
variable_set('location_maxnum_group', '0');
variable_set('location_maxnum_link', '0');
variable_set('location_maxnum_notes', '0');
variable_set('location_maxnum_webform', '1');
variable_set('location_name_bio', '0');
variable_set('location_name_discussion', '');
variable_set('location_name_group', '');
variable_set('location_name_link', '');
variable_set('location_name_notes', '');
variable_set('location_name_webform', '1');
variable_set('location_postal_code_bio', '1');
variable_set('location_postal_code_discussion', '0');
variable_set('location_postal_code_group', '0');
variable_set('location_postal_code_link', '0');
variable_set('location_postal_code_notes', '0');
variable_set('location_postal_code_webform', '1');
variable_set('location_province_bio', '1');
variable_set('location_province_discussion', '0');
variable_set('location_province_group', '0');
variable_set('location_province_link', '0');
variable_set('location_province_notes', '0');
variable_set('location_province_webform', '1');
variable_set('location_search_distance_unit', 'mile');
variable_set('location_street_bio', '0');
variable_set('location_street_discussion', '');
variable_set('location_street_group', '');
variable_set('location_street_link', '');
variable_set('location_street_notes', '');
variable_set('location_street_webform', '1');
variable_set('location_suppress_country', 0);
variable_set('location_usegmap', 1);
variable_set('location_user', '0');
variable_set('location_weight_bio', '9');
variable_set('location_weight_discussion', '9');
variable_set('location_weight_group', '9');
variable_set('location_weight_link', '9');
variable_set('location_weight_notes', '9');
variable_set('location_weight_webform', '9');
variable_set('menu_primary_menu', 2);
variable_set('menu_secondary_menu', 2);
variable_set('module_action', 'Enable');
variable_set('node_cron_comments_scale', 0.5);
variable_set('node_cron_last', '1184687785');
variable_set('node_cron_last_nid', '124');
variable_set('node_cron_views_scale', 1);
variable_set('og_approve_user_subject', 'Subscription request approved for \'@title\'');
variable_set('og_audience_checkboxes', 1);
variable_set('og_audience_required', false);
variable_set('og_deny_user_body', 'Sorry, your subscription request was denied.');
variable_set('og_deny_user_subject', 'Subscription request denied for \'@title\'');
variable_set('og_help', '');
variable_set('og_home_page_view', 'og_ghp_ron');
variable_set('og_invite_user_subject', 'Invitation to join the group \'@group\' at @site');
variable_set('og_member_pics', 1);
variable_set('og_new_admin_body', '@username, you are now an administrator for the group \'@group\'.

  You can administer this group by logging in here:
  !group_url');
variable_set('og_new_admin_subject', 'You are now an administrator for the group \'@group\'');
variable_set('og_new_node_subject', '@group: \'@title\' at @site');
variable_set('og_node_types', array (
    'webform' => 'webform',
    'group' => 'group',
));
variable_set('og_notification', '2');
variable_set('og_omitted', array (
));
variable_set('og_omitted_email_node_types', array (
    'bio' => 'bio',
    'link' => 'link',
    'notes' => 'notes',
    'page' => 'page',
    'session' => 'session',
));
variable_set('og_request_user_body', 'To instantly approve this request, visit !approve_url.
  You may deny this request or manage subscribers at !group_url. !request');
variable_set('og_request_user_subject', 'Subscription request for \'@group\' from \'@username\'');
variable_set('og_visibility', '0');
variable_set('og_visibility_directory', '2');
variable_set('og_visibility_registration', '3');
variable_set('pathauto_ignore_words', 'a,an,as,at,before,but,by,for,from,is,in,into,like,of,off,on,onto,per,since,than,the,this,that,to,up,via,with');
variable_set('pathauto_indexaliases', 0);
variable_set('pathauto_indexaliases_bulkupdate', false);
variable_set('pathauto_max_component_length', '100');
variable_set('pathauto_max_length', '100');
variable_set('pathauto_modulelist', array (
    0 => 'node',
    1 => 'taxonomy',
    2 => 'user',
));
variable_set('pathauto_node_applytofeeds', 0);
variable_set('pathauto_node_bio_pattern', '');
variable_set('pathauto_node_bulkupdate', false);
variable_set('pathauto_node_page_pattern', '');
variable_set('pathauto_node_pattern', '[title]');
variable_set('pathauto_node_session_pattern', 'session/[title]');
variable_set('pathauto_node_supportsfeeds', 'feed');
variable_set('pathauto_node_webform_pattern', 'conference/[title]');
variable_set('pathauto_quotes', '0');
variable_set('pathauto_separator', '-');
variable_set('pathauto_taxonomy_applytofeeds', 0);
variable_set('pathauto_taxonomy_bulkupdate', 0);
variable_set('pathauto_taxonomy_pattern', '[vocab]/[catpath]');
variable_set('pathauto_taxonomy_supportsfeeds', '0/feed');
variable_set('pathauto_update_action', '2');
variable_set('pathauto_user_bulkupdate', 0);
variable_set('pathauto_user_pattern', 'user/[user]');
variable_set('pathauto_user_supportsfeeds', NULL);
variable_set('pathauto_verbose', 0);
variable_set('pathauto_version', array (
    'text' => '2005-9-18',
    'build' => 5,
));
variable_set('pearwiki_filter_ignore_regexp_4', '');
variable_set('pearwiki_filter_ignore_tags_4', '<p> <li> <img>');
variable_set('pearwiki_filter_image_base_4', 'files/');
variable_set('pearwiki_filter_interwiki_mapping_4', 'Local drupal path | path | <path>
  groups.drupal.org | gdo | http://groups.drupal.org/freelinking/%s
  Wikipedia | wp | http://en.wikipedia.org/wiki/%s
  ');
variable_set('pearwiki_filter_pear_path_4', '/var/www/conference/sites/all/modules/pearwiki_filter/');
variable_set('pearwiki_filter_space_replacement_4', '-');
variable_set('pearwiki_filter_syntax_4', 'Mediawiki');
variable_set('pearwiki_filter_use_freelinking_4', 0);
variable_set('pearwiki_filter_use_image_4', 0);
variable_set('pearwiki_filter_use_liquid_4', 0);
variable_set('pearwiki_filter_use_wiki_links_4', 1);
variable_set('pearwiki_filter_use_wikitools_4', 1);
variable_set('pearwiki_filter_wikilink_base_4', 'wiki/');
variable_set('signup_close_early', '1');
variable_set('signup_form_conference_og', 0);
variable_set('signup_form_conference_signup', 1);
variable_set('signup_form_webform', 0);
variable_set('site_mail', 'admin@admin.com');
variable_set('site_mission', '');
variable_set('site_name', 'Conference');
variable_set('site_slogan', '');
variable_set('smtp_library', '');
variable_set('theme_default', 'cod_organizing');
variable_set('theme_garland_settings', array (
    'toggle_logo' => 1,
    'toggle_name' => 1,
    'toggle_slogan' => 0,
    'toggle_mission' => 1,
    'toggle_node_user_picture' => 0,
    'toggle_comment_user_picture' => 0,
    'toggle_search' => 0,
    'toggle_favicon' => 1,
    'default_logo' => 0,
    'logo_path' => '',
    'logo_upload' => '',
    'default_favicon' => 0,
    'favicon_path' => '',
    'favicon_upload' => '',
    'op' => 'Save configuration',
    'form_token' => 'd83416085c1265034cdea66b60254c14',
    'scheme' => '',
    'palette' => 
    array (
      'base' => '#636363',
      'link' => '#6f6f6f',
      'top' => '#818181',
      'bottom' => '#a7a7a7',
      'text' => '#4e4e4e',
    ),
    'theme' => 'garland',
    'info' => 
    array (
      'schemes' => 
      array (
        '#0072b9,#027ac6,#2385c2,#5ab5ee,#494949' => 'Blue Lagoon (Default)',
        '#464849,#2f416f,#2a2b2d,#5d6779,#494949' => 'Ash',
        '#55c0e2,#000000,#085360,#007e94,#696969' => 'Aquamarine',
        '#d5b048,#6c420e,#331900,#971702,#494949' => 'Belgian Chocolate',
        '#3f3f3f,#336699,#6598cb,#6598cb,#000000' => 'Bluemarine',
        '#d0cb9a,#917803,#efde01,#e6fb2d,#494949' => 'Citrus Blast',
        '#0f005c,#434f8c,#4d91ff,#1a1575,#000000' => 'Cold Day',
        '#c9c497,#0c7a00,#03961e,#7be000,#494949' => 'Greenbeam',
        '#ffe23d,#a9290a,#fc6d1d,#a30f42,#494949' => 'Mediterrano',
        '#788597,#3f728d,#a9adbc,#d4d4d4,#707070' => 'Mercury',
        '#5b5fa9,#5b5faa,#0a2352,#9fa8d5,#494949' => 'Nocturnal',
        '#7db323,#6a9915,#b5d52a,#7db323,#191a19' => 'Olivia',
        '#12020b,#1b1a13,#f391c6,#f41063,#898080' => 'Pink Plastic',
        '#b7a0ba,#c70000,#a1443a,#f21107,#515d52' => 'Shiny Tomato',
        '#18583d,#1b5f42,#34775a,#52bf90,#2d2d2d' => 'Teal Top',
        '' => 'Custom',
      ),
      'copy' => 
      array (
        0 => 'images/menu-collapsed.gif',
        1 => 'images/menu-expanded.gif',
        2 => 'images/menu-leaf.gif',
      ),
      'gradient' => 
      array (
        0 => 0,
        1 => 37,
        2 => 760,
        3 => 121,
      ),
      'fill' => 
      array (
        'base' => 
        array (
          0 => 0,
          1 => 0,
          2 => 760,
          3 => 568,
        ),
        'link' => 
        array (
          0 => 107,
          1 => 533,
          2 => 41,
          3 => 23,
        ),
      ),
      'slices' => 
      array (
        'images/body.png' => 
        array (
          0 => 0,
          1 => 37,
          2 => 1,
          3 => 280,
        ),
        'images/bg-bar.png' => 
        array (
          0 => 202,
          1 => 530,
          2 => 76,
          3 => 14,
        ),
        'images/bg-bar-white.png' => 
        array (
          0 => 202,
          1 => 506,
          2 => 76,
          3 => 14,
        ),
        'images/bg-tab.png' => 
        array (
          0 => 107,
          1 => 533,
          2 => 41,
          3 => 23,
        ),
        'images/bg-navigation.png' => 
        array (
          0 => 0,
          1 => 0,
          2 => 7,
          3 => 37,
        ),
        'images/bg-content-left.png' => 
        array (
          0 => 40,
          1 => 117,
          2 => 50,
          3 => 352,
        ),
        'images/bg-content-right.png' => 
        array (
          0 => 510,
          1 => 117,
          2 => 50,
          3 => 352,
        ),
        'images/bg-content.png' => 
        array (
          0 => 299,
          1 => 117,
          2 => 7,
          3 => 200,
        ),
        'images/bg-navigation-item.png' => 
        array (
          0 => 32,
          1 => 37,
          2 => 17,
          3 => 12,
        ),
        'images/bg-navigation-item-hover.png' => 
        array (
          0 => 54,
          1 => 37,
          2 => 17,
          3 => 12,
        ),
        'images/gradient-inner.png' => 
        array (
          0 => 646,
          1 => 307,
          2 => 112,
          3 => 42,
        ),
        'logo.png' => 
        array (
          0 => 622,
          1 => 51,
          2 => 64,
          3 => 73,
        ),
        'screenshot.png' => 
        array (
          0 => 0,
          1 => 37,
          2 => 400,
          3 => 240,
        ),
        ),
        'blend_target' => '#ffffff',
        'preview_image' => 'color/preview.png',
        'preview_css' => 'color/preview.css',
        'base_image' => 'color/base.png',
        ),
        ));
variable_set('theme_cod_organizing_settings', array (
    'toggle_logo' => 1,
    'toggle_name' => 0,
    'toggle_slogan' => 0,
    'toggle_mission' => 0,
    'toggle_node_user_picture' => 0,
    'toggle_comment_user_picture' => 1,
    'toggle_search' => 0,
    'toggle_favicon' => 1,
    'default_logo' => 0,
    'logo_path' => 'sites/all/themes/cod_organizing/small_logo.png',
    'logo_upload' => '',
    'default_favicon' => 1,
    'favicon_path' => '',
    'favicon_upload' => '',
    'op' => 'Save configuration',
    'form_token' => '7fb9635d94fe4d8d917483b35614650c',
));
variable_set('theme_settings', array (
    'toggle_node_info_page' => false,
));
variable_set('update_access_fixed', true);
variable_set('update_status_last', 1184690410);
variable_set('upload_discussion', '0');
variable_set('upload_group', '0');
variable_set('upload_link', '0');
variable_set('upload_notes', '0');
variable_set('upload_webform', '0');
variable_set('user_picture_default', 'sites/all/themes/cod_organizing/images/default-avatar.png');
variable_set('user_picture_dimensions', '55x55');
variable_set('user_picture_file_size', '30');
variable_set('user_picture_guidelines', '');
variable_set('user_picture_path', 'pictures');
variable_set('user_pictures', '1');
variable_set('user_registration_help', '');
variable_set('vote_up_down_anonymous_vote', '0');
variable_set('vote_up_down_link_comment', '0');
variable_set('vote_up_down_link_node', '3');
variable_set('vote_up_down_node_types', array (
    'session' => 'session',
    'webform' => 0,
    'page' => 0,
));
variable_set('vote_up_down_reset_vote', '0');
variable_set('vote_up_down_tag', 'digg');
variable_set('vote_up_down_widget_comment', '0');
variable_set('vote_up_down_widget_node', '3');
variable_set('vote_up_down_widget_style_comment', '1');
variable_set('vote_up_down_widget_style_node', '1');
variable_set('wikitools_hijack_freelinking', 1);
variable_set('wikitools_main_page_title', 'Main Page');
variable_set('wikitools_node_types', array (
    'notes' => 'notes',
));
variable_set('wikitools_options', array (
    'node creation' => 'node creation',
    'node search' => 'node search',
    'auto redirect' => 'auto redirect',
    'unique titles' => 'unique titles',
    'move protection' => 'move protection',
    'delete protection' => 'delete protection',
    'underscore as space' => 'underscore as space',
));
variable_set('wikitools_path', 'wiki');

  // General Stuff
  // --------------
  // Set site name
variable_set('site_name', st('Drupal Conference Organizing Website'));

// Front page
variable_set('site_frontpage', 'home');

// Set up Admin User
install_add_user('admin', 'admin', 'admin@admin.com', $roles = array(), $status = 1);
$user = user_authenticate('admin', 'admin');
$edit = array();
conference_organizing_bio_create_profile($user, $edit);
$bio = node_load(bio_for_user(1));
$bio->field_first_name[0]['value'] = 'Admin';
$bio->field_last_name[0]['value'] = 'User';
$bio->field_organization[0]['value'] = 'Conference Admin';
node_save($bio);

// Set up Chat Node
$node = array(
  'title' => 'Conference Chats',
  'type' => 'chatroom',
  'uid' => 1,
  'name' => 'admin',
  'status' => 1,
  'comment' => 0,
  'promote' => 1,
  'revision' => 1,
  'format' => 4,
  'body' => '');
$node = node_submit($node);
node_save($node);

  // Clean up
  // --------

  system_modules();
  cache_clear_all();
  menu_rebuild();
  node_types_rebuild();
}

// Functions from crud.inc. 
/**
 * Set the permission for a certain role
 */
function install_set_permissions($rid, $perms) {
  db_query('DELETE FROM {permission} WHERE rid = %d', $rid);
  db_query("INSERT INTO {permission} (rid, perm) VALUES (%d, '%s')", $rid, implode(', ', $perms));
}

/**
 * Add a user
 */
function install_add_user($username, $password, $email, $roles = array(), $status = 1) {
  user_save(
    new stdClass(),
    array(
      'name' => $username, 
      'pass' => $password,
      'mail' => $email,
      'roles' => $roles,
      'status' => $status
    )
  );
}

/**
 * Add a role to the roles table.
 */
function install_add_role($name) {
  db_query("INSERT INTO {role} (name) VALUES ('%s')", $name);
  return install_get_rid($name);
}
/**
* Set default theme
* @param        $theme  Unique string that is the name of theme
*/
function install_default_theme($theme) {
  install_enable_theme($theme);
  variable_set('theme_default', $theme);
}

/**
* Set admin theme
* @param        $theme  Unique string that is the name of theme
*/
function install_admin_theme($theme) {
  variable_set('admin_theme', $theme);
}

/**
 * Enable theme
 * @param        $theme  Unique string that is the name of theme
 */
function install_enable_theme($theme) {
  system_theme_data();
  db_query("UPDATE {system} SET status = 1 WHERE type = 'theme' and name = '%s'", $theme);
  system_initialize_theme_blocks($theme);
}

/**
 * Get the role id for the role name
 */
function install_get_rid($name) {
  return db_result(db_query("SELECT rid FROM {role} WHERE name ='%s' LIMIT 1", $name));
}
