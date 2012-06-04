<?php // $Id: node.tpl.php,v 1.1 2009/05/15 07:28:06 agileware Exp $ ?>
<div class="Post">
  <div class="Post-body">
    <div class="Post-inner">
      <?php if ($teaser): ?>
        <h2 class="PostHeaderIcon-wrapper"> <span class="PostHeader"><a href="<?php echo $node_url; ?>" title="<?php echo $title; ?>"><?php echo $title; ?></a></span></h2>
      <?php endif; ?>
      <div class="PostHeaderIcons metadata-icons">
        <?php if ($submitted) { echo art_submitted_worker($submitted, $date, $name);} ?>
      </div>
      <div class="PostContent">
        <div class="article">
          <?php echo $content;?>
          <?php if (isset($node->links['node_read_more'])) { echo '<div class="read_more">'.get_html_link_output($node->links['node_read_more']).'</div>'; } ?>
        </div>
      </div>
      <div class="cleared"></div>
      <?php ob_start(); ?>
      <div class="PostFooterIcons metadata-icons">
        <?php if ($links) { echo art_links_woker($node->links);} ?>
        <?php if ($terms) { echo art_terms_worker($node);} ?>
      </div>
      <?php $metadataContent = ob_get_clean(); ?>
      <?php if (trim($metadataContent) != ''): ?>
        <div class="PostMetadataFooter">
          <?php echo $metadataContent; ?>
        </div>
      <?php endif; ?>
    </div>
  </div>
</div>
