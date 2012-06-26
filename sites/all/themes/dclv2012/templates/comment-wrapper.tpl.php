<?php if ($content): ?>
  <div id="comments" class="<?php print $classes; ?>">
    <?php if ($node->comment_count != 0): ?>
      <h2 id="comments-title">
        <?php print t('Comments'); ?>
      </h2>
    <?php endif; ?>
    <?php print $content; ?>
  </div>
<?php endif; ?>