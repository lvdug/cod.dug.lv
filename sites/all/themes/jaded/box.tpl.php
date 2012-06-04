<?php // $Id: box.tpl.php,v 1.1 2009/05/15 07:28:06 agileware Exp $ ?>
<div class="box">
  <div class="Block">
    <div class="Block-tl"></div>
    <div class="Block-tr"></div>
    <div class="Block-bl"></div>
    <div class="Block-br"></div>
    <div class="Block-tc"></div>
    <div class="Block-bc"></div>
    <div class="Block-cl"></div>
    <div class="Block-cr"></div>
    <div class="Block-cc"></div>
    <div class="Block-body">
      <?php if ($title): ?>
        <div class="BlockHeader">
          <div class="l"></div>
          <div class="r"></div>
          <div class="header-tag-icon">
            <div class="t">
              <?php echo $title; ?>
            </div>
          </div>
        </div>
      <?php endif; ?>
      <div class="BlockContent">
        <div class="BlockContent-body">
          <?php echo $content; ?>
        </div>
      </div>
    </div>
  </div>
</div>
