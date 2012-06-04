<?php // $Id: page.tpl.php,v 1.1 2009/05/15 07:28:06 agileware Exp $ ?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" lang="<?php echo $language->language; ?>" xml:lang="<?php echo $language->language; ?>">

  <head>
    <title><?php if (isset($head_title )) { echo $head_title; } ?></title>
    <meta http-equiv="X-UA-Compatible" content="IE=EmulateIE7" />
    <?php echo $head; ?>  
    <?php echo $styles ?>
    <?php echo $scripts ?>
    <!--[if IE 6]><link rel="stylesheet" href="<?php echo $base_path . $directory; ?>/style.ie6.css" type="text/css" /><![endif]-->  
    <!--[if IE 7]><link rel="stylesheet" href="<?php echo $base_path . $directory; ?>/style.ie7.css" type="text/css" media="screen" /><![endif]-->
    <script type="text/javascript"><?php /* Needed to avoid Flash of Unstyle Content in IE */ ?> </script>
  </head>

  <body>
    <div class="PageBackgroundGradient"></div>
    <div class="PageBackgroundGlare">
      <div class="PageBackgroundGlareImage"></div>
    </div>
    <div class="Main">
      <div class="Sheet">
        <div class="Sheet-tl"></div>
        <div class="Sheet-tr"></div>
        <div class="Sheet-bl"></div>
        <div class="Sheet-br"></div>
        <div class="Sheet-tc"></div>
        <div class="Sheet-bc"></div>
        <div class="Sheet-cl"></div>
        <div class="Sheet-cr"></div>
        <div class="Sheet-cc"></div>
        <div class="Sheet-body">
          <div class="Header">
            <!--div class="Header-png"></div>
            <div class="Header-jpeg"></div-->
            <div class="logo">
              <?php if ($logo): ?>
                <a href="<?php print $base_path ?>" title="<?php print t('Home') ?>"><img src="<?php print $logo ?>" alt="<?php print t('Home') ?>" /></a>
              <?php endif; ?>
            </div>
          </div>
          <?php if ($navigation): ?>
            <div class="nav">
              <div class="l"></div>
              <div class="r"></div>
              <?php echo $navigation; ?>
            </div>
          <?php endif; ?>
          <div class="contentLayout">
            <?php if ($left) echo '<div class="sidebar1">' . $left . "</div>"; 
                  else if ($sidebar_left) echo '<div class="sidebar1">' . $sidebar_left . "</div>";?>
            <div class="<?php $l = NULL; if (!empty($left)) $l = left; else if ($sidebar_left) $l = sidebar_left;
                              $r = NULL; if (!empty($right)) $r = right; else if ($sidebar_right) $r = sidebar_right;
                              echo artxGetContentCellStyle($l, $r, $content); ?>">
              <div class="Post">
                <div class="Post-body">
                  <div class="Post-inner">
                    <div class="PostContent">
                      <?php if ($breadcrumb): echo theme('breadcrumb', $breadcrumb); endif; ?>
                      <?php if ($tabs): echo '<div id="tabs-wrapper" class="clear-block">'; endif; ?>
                      <?php if ($title): echo '<h2 class="PostHeaderIcon-wrapper'. ($tabs ? ' with-tabs' : '') .'">'. $title .'</h2>'; endif; ?>
                      <?php if ($tabs): echo $tabs . '</div>'; endif; ?>
                      <?php if ($tabs2): echo '<ul class="tabs secondary">'. $tabs2 .'</ul>'; endif; ?>
                      <?php if ($mission): echo '<div id="mission">' . $mission . '</div>'; endif; ?>
                      <?php if ($help): echo $help; endif; ?>
                      <?php if ($show_messages && $messages): echo $messages; endif; ?>
                      <?php echo art_content_replace($content); ?>
                    </div>
                    <div class="cleared"></div>
                  </div>
                </div>
              </div>
            </div>
            <?php if ($right) echo '<div class="sidebar2">' . $right . "</div>"; 
                  else if ($sidebar_right) echo '<div class="sidebar2">' . $sidebar_right . "</div>";?>
          </div>
          <div class="cleared"></div>
          <div class="Footer">
            <div class="Footer-inner">
              <a href="<?php $feedsUrls = array_keys(drupal_add_feed()); if(isset($feedsUrls[0]) && strlen($feedsUrls[0])>0) {echo $feedsUrls[0];} ?>" class="rss-tag-icon" title="RSS"></a>
              <div class="Footer-text">
                <?php if (!empty($footer)) { echo $footer; } ?>
              </div>
            </div>
            <div class="Footer-background"></div>
          </div>
        </div>
      </div>
      <div class="cleared"></div>
      <p class="page-footer"><?php echo $footer_message; ?></p>
    </div>
    <?php print $closure; ?>
  </body>
</html>
