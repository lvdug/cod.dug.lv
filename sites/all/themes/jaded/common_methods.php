<?php
// $Id: common_methods.php,v 1.1 2009/05/15 07:28:06 agileware Exp $

/**
 * Generate the HTML representing a given menu with Artisteer style.
 *
 * @param $mid
 *   The block navigation content.
 *
 * @ingroup themeable
 */
function art_navigation_links_worker($content = NULL) {
  if (!$content) {
    return '';
  }

  $output = $content;
  $menu_str = ' class="menu"';
  if(strpos($content, $menu_str) !== FALSE) {
    $empty_str = '';
    $pattern = '/class="menu"/i';
    $replacement = 'class="artmenu"';
    $output = preg_replace($pattern, $replacement, $output, 1);
    $output = str_replace($menu_str, $empty_str, $output);
  }
  $output = preg_replace('~(<a [^>]*>)([^<]*)(</a>)~', '$1<span class="l"></span><span class="r"></span><span class="t">$2</span>$3', $output);

  return $output;
}

/**
 * Split out taxonomy terms by vocabulary.
 *
 * @param $node
 *   An object providing all relevant information for displaying a node:
 *   - $node->nid: The ID of the node.
 *   - $node->type: The content type (story, blog, forum...).
 *   - $node->title: The title of the node.
 *   - $node->created: The creation date, as a UNIX timestamp.
 *   - $node->teaser: A shortened version of the node body.
 *   - $node->body: The entire node contents.
 *   - $node->changed: The last modification date, as a UNIX timestamp.
 *   - $node->uid: The ID of the author.
 *   - $node->username: The username of the author.
 *
 * @ingroup themeable
 */
function art_terms_worker($node) {
  $output = '';
  if (isset($node->links)) {
    $output = '&nbsp;&nbsp;|&nbsp;';
  }
  $terms = $node->taxonomy;

  if ($terms) {
    $links = array();
    ob_start();?><img class="metadata-icon" src="<?php echo get_full_path_to_theme(); ?>/images/PostTagIcon.png" width="18" height="18" alt="PostTagIcon"/> <?php
    $output .= ob_get_clean();
    $output .= t('Tags: ');
    foreach ($terms as $term) {
      $links[] = l($term->name, taxonomy_term_path($term), array('rel' => 'tag', 'title' => strip_tags($term->description)));
    }
    $output .= implode(', ', $links);
    $output .= ', ';
  }

  $output = substr($output, 0, strlen($output)-2); // removes last comma with space
  return $output;
}

/**
 * Return a themed set of links.
 *
 * @param $links
 *   A keyed array of links to be themed.
 * @param $attributes
 *   A keyed array of attributes
 * @return
 *   A string containing an unordered list of links.
 */
function art_links_woker($links, $attributes = array('class' => 'links')) {
  $output = '';

  if (count($links) > 0) {
    $output = '';
    $num_links = count($links);
    $index = 0;

    foreach ($links as $key => $link) {
      $class = $key;
      if (strpos ($class, "read_more") !== FALSE) {
        break;
      }

      // Automatically add a class to each link and also to each LI
      if (isset($link['attributes']) && isset($link['attributes']['class'])) {
        $link['attributes']['class'] .= ' ' . $key;
      }
      else {
        $link['attributes']['class'] = $key;
      }

      if ($index > 0) {
        $output .= '&nbsp;&nbsp;|&nbsp;';
      }

      // Add first and last classes to the list of links to help out themers.
      $extra_class = '';
      if ($index == 1) {
        $extra_class .= 'first ';
      }
      if ($index == $num_links) {
        $extra_class .= 'last ';
      }

      if ($class) {
        if (strpos ($class, "comment") !== FALSE) {
          ob_start();?><img class="metadata-icon" src="<?php echo get_full_path_to_theme(); ?>/images/PostCommentsIcon.png" width="18" height="18" alt="PostCommentsIcon"/> <?php
          $output .= ob_get_clean();
        }
        else {
          ob_start();?><img class="metadata-icon" src="<?php echo get_full_path_to_theme(); ?>/images/PostCategoryIcon.png" width="18" height="18" alt="PostCategoryIcon"/> <?php
          $output .= ob_get_clean();
        }
      }

      $index++;
      $output .= get_html_link_output($link);
    }
  }

  return $output;
}

function get_html_link_output($link) {
  $output = '';
  // Is the title HTML?
  $html = isset($link['html']) && $link['html'];

  // Initialize fragment and query variables.
  $link['query'] = isset($link['query']) ? $link['query'] : NULL;
  $link['fragment'] = isset($link['fragment']) ? $link['fragment'] : NULL;

  if (isset($link['href'])) {
    $output = l($link['title'], $link['href'], array('language' => $link['language'], 'attributes'=>$link['attributes'], 'query'=>$link['query'], 'fragment'=>$link['fragment'], 'absolute'=>FALSE, 'html'=>$html));
  }
  else if ($link['title']) {
    //Some links are actually not links, but we wrap these in <span> for adding title and class attributes
    if (!$html) {
      $link['title'] = check_plain($link['title']);
    }
    $output = $link['title'];
  }

  return $output;
}

/**
 * Format the forum body.
 *
 * @ingroup themeable
 */
function art_content_replace($content) {
  $first_time_str = '<div id="first-time"';
  $article_str = 'class="article"';
  $pos = strpos($content, $first_time_str);
  if($pos !== FALSE) {
    $output = str_replace($first_time_str, $first_time_str . $article_str, $content);
    $output = <<< EOT
<div class="Post">
  <div class="Post-body">
    <div class="Post-inner">
      <div class="PostContent">
        $output
      </div>
    <div class="cleared"></div>
    </div>
  </div>
</div>
EOT;
  }
  else {
    $output = $content;
  }
  return $output;
}

function artxGetContentCellStyle($left, $right, $content) {
  if (!empty($left) && !empty($right))
    return 'content';
  if (!empty($right))
    return 'content-sidebar1';
  if (!empty($left) > 0)
    return 'content-sidebar2';
  return 'content-wide';
}

function art_submitted_worker($submitted, $date, $name) {
  $output = '';
  ob_start();?><img class="metadata-icon" src="<?php echo get_full_path_to_theme(); ?>/images/PostDateIcon.png" width="17" height="18" alt="PostDateIcon"/> <?php
  $output .= ob_get_clean();
  $output .= $date;
  $output .= '&nbsp;|&nbsp;';
  ob_start();?><img class="metadata-icon" src="<?php echo get_full_path_to_theme(); ?>/images/PostAuthorIcon.png" width="14" height="14" alt="PostAuthorIcon"/> <?php
  $output .= ob_get_clean();
  $output .= $name;
  return $output;
}
