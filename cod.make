; Conference Organizing Distribution dev snapshot makefile
; The purpose of this makefile is to make it easier for people to install
; the dev version of COD and its dependencies, including patches, before
; a new full release of the distribution is rolled.  

api = 2
core = 7.x

; Required versions of Drupal contributed projects.
projects[admin][subdir] = contrib

projects[auto_nodetitle][subdir] = contrib

projects[comment_notify][subdir] = contrib

projects[context][subdir] = contrib

projects[ctools][subdir] = contrib

projects[strongarm][subdir] = contrib
projects[strongarm][download][type] = "git"
projects[strongarm][download][url] = "http://git.drupal.org/project/strongarm.git"
projects[features][download][branch] = "7.x-2.x"
 
 
projects[link][subdir] = contrib

projects[date][subdir] = contrib

projects[diff][subdir] = contrib

projects[flag][subdir] = contrib
projects[flag][download][type] = "git"
projects[flag][download][url] = "http://git.drupal.org/project/flag.git"
projects[flag][download][branch] = "master"

projects[features][subdir] = contrib
projects[features][download][type] = "git"
projects[features][download][url] = "http://git.drupal.org/project/features.git"
projects[features][download][branch] = "7.x-1.x"

; These patches probably need to be re-rolled (and ideally, committed to both the D6 and D7 branches)
; projects[features][download][url] = "http://git.drupal.org/project/features.git"
; http://drupal.org/node/968826#comment-3863422
; projects[features][patch][] = "http://drupal.org/files/issues/968826-features-menu-uuid.patch"
; http://drupal.org/node/912716#comment-3899924
; projects[features][patch][] ="http://drupal.org/files/issues/features-profile-fields-912716-11.patch"
; http://drupal.org/node/860974#comment-3505484
; projects[features][patch][] = "http://drupal.org/files/issues/features.860974.patch"

projects[globalredirect][subdir] = contrib

projects[imageapi][subdir] = contrib

projects[imagecache][subdir] = contrib

projects[jquery_ui][subdir] = contrib

projects[markdown][subdir] = contrib

projects[pathauto][subdir] = contrib

projects[path_redirect][subdir] = contrib

projects[skinr][subdir] = contrib

projects[signup][subdir] = contrib
projects[signup][download][type] = "git"
projects[signup][download][url] = "http://git.drupal.org/project/signup.git"

projects[skinr][subdir] = contrib

projects[token][subdir] = contrib

; Is there a commerce_signup? Needs to be checked
; projects[uc_signup][subdir] = contrib

projects[uuid][subdir] = contrib
; projects[uuid][download][type] = "git"
; projects[uuid][download][url] = "http://git.drupal.org/project/uuid.git"
; projects[uuid][download][revision] = "6.x-1.x"

projects[uuid_features][subdir] = contrib
projects[uuid_features][download][type] = "git"
projects[uuid_features][download][url] = "http://git.drupal.org/project/uuid_features.git"
projects[uuid_features][download][revision] = "7.x-1.x"

projects[commerce][subdir] = contrib

projects[views][subdir] = contrib

projects[views_bulk_operations][subdir] = contrib


projects[fusion][type] = theme
projects[fusion][download][type] = git
projects[fusion][download][url] = "http://git.drupal.org/project/fusion.git"
projects[fusion][download][revision] = "7.x-1.x"

; COD feature modules.
projects[cod_support][subdir] = contrib 
projects[cod_support][download][url] = "http://git.drupal.org/project/cod_support.git"
projects[cod_support][download][revision] = "7.x-1.x"

; Libraries
libraries[jquery_ui][download][type] = "get"
libraries[jquery_ui][destination] = "modules/contrib/jquery_ui"


libraries[jquery_ui][download][url] = "http://jquery-ui.googlecode.com/files/jquery.ui-1.6.zip"
libraries[jquery_ui][directory_name] = "jquery.ui"

