<?php // $Id: comment.tpl.php,v 1.1 2009/05/15 07:28:06 agileware Exp $ ?>
<div class="Post">
  <div class="Post-body">
    <div class="Post-inner">
      <div class="comment<?php if ($comment->status == COMMENT_NOT_PUBLISHED) echo ' comment-unpublished'; ?>">
        <h2 class="PostHeaderIcon-wrapper">
          <span class="PostHeader">
            <?php if ($picture) {echo $picture; } ?>
            <?php if ($title) {echo $title; } ?>
            <?php if ($new) echo '<span class="new-text">' . $new . '</span>'; ?>
          </span>
        </h2>
        <?php if ($submitted): ?>
          <div class="submitted">
            <?php echo $submitted; ?>
          </div>
          <div class="cleared"></div><br/>
        <?php endif; ?>
        <div class="PostContent">
          <?php echo $content; ?>
        </div>
        <div class="cleared"></div>
        <div class="links">
          <?php echo $links; ?>
          <div class="cleared"></div>
        </div>
      </div>
    </div>
  </div>
</div>
