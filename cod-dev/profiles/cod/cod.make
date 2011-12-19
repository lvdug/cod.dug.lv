; Conference Organizing Distribution dev snapshot makefile
; The purpose of this makefile is to make it easier for people to install
; the dev version of COD and its dependencies, including patches, before
; a new full release of the distribution is rolled.

api = 2
core = 7.x

; Required versions of Drupal contributed projects.

;Admin
projects[admin][install_path] = sites/all/modules/contrib
projects[admin][download][type] = "git"
projects[admin][download][url] = "http://git.drupal.org/project/admin.git"
projects[admin][download][revision] = "7.x-2.x"

;Automatic Nodetitles
projects[auto_nodetitle][install_path] = sites/all/modules/contrib
projects[auto_nodetitle][download][type] = "git"
projects[auto_nodetitle][download][url] = "http://git.drupal.org/project/auto_nodetitle.git"
projects[auto_nodetitle][download][revision] = "7.x-1.x"

;Comment Notify
projects[comment_notify][install_path] = sites/all/modules/contrib
projects[comment_notify][download][type] = "git"
projects[comment_notify][download][url] = "http://git.drupal.org/project/comment_notify.git"
projects[comment_notify][download][revision] = "7.x-1.x"

;Context
projects[context][install_path] = sites/all/modules/contrib
projects[context][download][type] = "git"
projects[context][download][url] = "http://git.drupal.org/project/context.git"
projects[context][download][revision] = "7.x-3.x"

;Chaos tool suite
projects[ctools][install_path] = sites/all/modules/contrib
projects[ctools][download][type] = "git"
projects[ctools][download][url] = "http://git.drupal.org/project/ctools.git"
projects[ctools][download][revision] = "7.x-1.x"

;Strongarm
projects[strongarm][install_path] = sites/all/modules/contrib
projects[strongarm][download][type] = "git"
projects[strongarm][download][url] = "http://git.drupal.org/project/strongarm.git"
projects[strongarm][download][revision] = "7.x-2.x"

;Link
projects[link][install_path] = sites/all/modules/contrib
projects[link][download][type] = "git"
projects[link][download][url] = "http://git.drupal.org/project/link.git"
projects[link][download][revision] = "7.x-1.x"

;Date
projects[date][install_path] = sites/all/modules/contrib
projects[date][download][type] = "git"
projects[date][download][url] = "http://git.drupal.org/project/date.git"
projects[date][download][revision] = "7.x-2.x"

;Diff
projects[diff][install_path] = sites/all/modules/contrib
projects[diff][download][type] = "git"
projects[diff][download][url] = "http://git.drupal.org/project/diff.git"
projects[diff][download][revision] = "7.x-2.x"

;Flag
projects[flag][install_path] = sites/all/modules/contrib
projects[flag][download][type] = "git"
projects[flag][download][url] = "http://git.drupal.org/project/flag.git"
projects[flag][download][branch] = "master"

;Features
projects[features][install_path] = sites/all/modules/contrib
projects[features][download][type] = "git"
projects[features][download][url] = "http://git.drupal.org/project/features.git"
projects[features][download][branch] = "7.x-1.x"

;Global Redirect
projects[globalredirect][install_path] = sites/all/modules/contrib
projects[globalredirect][download][type] = "git"
projects[globalredirect][download][url] = "http://git.drupal.org/project/globalredirect.git"
projects[globalredirect][download][revision] = "7.x-1.x"

;ImageAPI
projects[imageapi][install_path] = sites/all/modules/contrib
projects[imageapi][download][type] = "git"
projects[imageapi][download][url] = "http://git.drupal.org/project/imageapi.git"
projects[imageapi][download][revision] = "master"

;jQuery UI
projects[jquery_ui][install_path] = sites/all/modules/contrib
projects[jquery_ui][download][type] = "git"
projects[jquery_ui][download][url] = "http://git.drupal.org/project/jquery_ui.git"
projects[jquery_ui][download][revision] = "7.x-1.x"

;Markdown filter
projects[markdown][install_path] = sites/all/modules/contrib
projects[markdown][download][type] = "git"
projects[markdown][download][url] = "http://git.drupal.org/project/markdown.git"
projects[markdown][download][revision] = "7.x-1.x"

;Pathauto
projects[pathauto][install_path] = sites/all/modules/contrib
projects[pathauto][download][type] = "git"
projects[pathauto][download][url] = "http://git.drupal.org/project/pathauto.git"
projects[pathauto][download][revision] = "7.x-1.x"

;Redirect
projects[redirect][install_path] = sites/all/modules/contrib
projects[redirect][download][type] = "git"
projects[redirect][download][url] = "http://git.drupal.org/project/redirect.git"
projects[redirect][download][revision] = "7.x-1.x"

;Skinr
projects[skinr][install_path] = sites/all/modules/contrib
projects[skinr][download][type] = "git"
projects[skinr][download][url] = "http://git.drupal.org/project/skinr.git"
projects[skinr][download][revision] = "7.x-1.x"

;Signup
projects[signup][install_path] = sites/all/modules/contrib
projects[signup][download][type] = "git"
projects[signup][download][url] = "http://git.drupal.org/project/signup.git"
projects[signup][download][revision] = "7.x-1.x"

;Token
projects[token][install_path] = sites/all/modules/contrib
projects[token][download][type] = "git"
projects[token][download][url] = "http://git.drupal.org/project/token.git"
projects[token][download][revision] = "7.x-1.x"

;Universally Unique IDentifier
projects[uuid][install_path] = sites/all/modules/contrib
projects[uuid][download][type] = "git"
projects[uuid][download][url] = "http://git.drupal.org/project/uuid.git"
projects[uuid][download][revision] = "7.x-1.x"

;UUID Features Integration
projects[uuid_features][install_path] = sites/all/modules/contrib
projects[uuid_features][download][type] = "git"
projects[uuid_features][download][url] = "http://git.drupal.org/project/uuid_features.git"
projects[uuid_features][download][revision] = "7.x-1.x"

;Commerce
projects[commerce][install_path] = sites/all/modules/contrib
projects[commerce][download][type] = "git"
projects[commerce][download][url] = http://git.drupal.org/project/commerce.git
projects[commerce][download][revision] = "7.x-1.x"

;Views
projects[views][install_path] = sites/all/modules/contrib
projects[views][download][type] = "git"
projects[views][download][url] = "http://git.drupal.org/project/views.git"
projects[views][download][revision] = "7.x-3.x"

;Views Bulk Operations (VBO)
projects[views_bulk_operations][install_path] = sites/all/modules/contrib
projects[views_bulk_operations][download][type] = "git"
projects[views_bulk_operations][download][url] = "http://git.drupal.org/project/views_bulk_operations.git"
projects[views_bulk_operations][download][revision] = "7.x-3.x"

;COD feature modules.
projects[cod_support][install_path] = sites/all/modules/contrib
projects[cod_support][download][type] = "git"
projects[cod_support][download][url] = "http://git.drupal.org/project/cod_support.git"
projects[cod_support][download][revision] = "7.x-1.x"

;Fusion
projects[fusion][type] = theme
projects[fusion][download][type] = git
projects[fusion][download][url] = "http://git.drupal.org/project/fusion.git"
projects[fusion][download][revision] = "master"
projects[fusion][install_path] = sites/all/themes
projects[fusion][destination] = fusion

;Libraries
libraries[jquery_ui][download][type] = "get"
libraries[jquery_ui][destination] = "jquery_ui"
libraries[jquery_ui][download][url] = "http://jquery-ui.googlecode.com/files/jquery.ui-1.6.zip"
libraries[jquery_ui][directory_name] = "jquery.ui"
libraries[jquery_ui][install_path] = sites/all/modules/contrib


; @todo: Is there a commerce_signup? Needs to be checked
; projects[uc_signup][install_path] = sites/all/modules/contrib

; @todo: These patches probably need to be re-rolled (and ideally, committed to both the D6 and D7 branches)
; projects[features][download][url] = "http://git.drupal.org/project/features.git"
; http://drupal.org/node/968826#comment-3863422
; projects[features][patch][] = "http://drupal.org/files/issues/968826-features-menu-uuid.patch"
; http://drupal.org/node/912716#comment-3899924
; projects[features][patch][] ="http://drupal.org/files/issues/features-profile-fields-912716-11.patch"
; http://drupal.org/node/860974#comment-3505484
; projects[features][patch][] = "http://drupal.org/files/issues/features.860974.patch"