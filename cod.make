; Conference Organizing Install Profile makefile
api = 2
; Required version of Drupal core.
core = 6.x

; The following line is removed for the d.o hosted version, but allows this to run in drush make in general without the --drupal-org switch.
projects[drupal] = 6.20

; Required versions of Drupal contributed projects.
projects[admin][subdir] = contrib

projects[cck][subdir] = contrib

projects[auto_nodetitle][subdir] = contrib

projects[comment_notify][subdir] = contrib

projects[context][subdir] = contrib
projects[context][version] = 3.0

projects[ctools][subdir] = contrib
projects[ctools][version] = 1.7

projects[strongarm][subdir] = contrib

projects[link][subdir] = contrib

projects[date][subdir] = contrib

projects[diff][subdir] = contrib

projects[checkbox_validate][subdir] = contrib

projects[emfield][subdir] = contrib

projects[fasttoggle][subdir] = contrib

projects[flag][subdir] = contrib
projects[flag][version] = 2.0-beta3
; http://drupal.org/node/846826
projects[flag][patch][] = "http://drupal.org/files/issues/flag_features_export.patch"

; CVS checkout of Features 6.x-1.x
projects[features][subdir] = contrib
projects[features][download][type] = "cvs"
projects[features][download][module] = "contributions/modules/features/"
projects[features][download][revision] = "DRUPAL-6--1"
; http://drupal.org/node/968826#comment-3863422
projects[features][patch][] = "http://drupal.org/files/issues/968826-features-menu-uuid.patch"
; http://drupal.org/node/912716#comment-3899924
projects[features][patch][] ="http://drupal.org/files/issues/features-profile-fields-912716-11.patch"
; http://drupal.org/node/860974#comment-3505484
projects[features][patch][] = "http://drupal.org/files/issues/features.860974.patch"

projects[filefield][subdir] = contrib

projects[globalredirect][subdir] = contrib

projects[imagefield][subdir] = contrib

projects[imageapi][subdir] = contrib

projects[imagecache][subdir] = contrib

projects[jquery_ui][subdir] = contrib

projects[markdown][subdir] = contrib

projects[pathauto][subdir] = contrib

projects[path_redirect][subdir] = contrib

projects[skinr][subdir] = contrib

projects[signup][subdir] = contrib

projects[skinr][subdir = contrib

projects[token][subdir] = contrib

projects[uc_signup][subdir] = contrib

projects[uuid][subdir] = contrib
projects[uuid][download][type] = "cvs"
projects[uuid][download][module] = "contributions/modules/uuid/"
projects[uuid][download][revision] = "DRUPAL-6--1"

projects[uuid_features][subdir] = contrib
projects[uuid_features][download][type] = "cvs"
projects[uuid_features][download][module] = "contributions/modules/uuid_features/"
projects[uuid_features][download][revision] = "DRUPAL-6--1"
; http://drupal.org/node/1008496#comment-3995594
projects[uuid_features][patch][] = "http://drupal.org/files/issues/node-values_0.diff"
projects[ubercart][subdir] = contrib

projects[views][subdir] = contrib

projects[views_bulk_operations][subdir] = contrib

projects[acquia_prosper][type] = theme
projects[acquia_prosper][subdir] = themes

projects[fusion][type] = theme
projects[fusion][download][type] = cvs
projects[fusion][download][module] = "contributions/themes/fusion"
projects[fusion][download][revision] = DRUPAL-6--1
; http://drupal.org/node/1012882
projects[fusion][patch][] = "http://drupal.org/files/issues/fusion-preprocess-node-content.patch"

; COD feature modules.
projects[cod_support][subdir] = contrib 
projects[cod_support][version] = 1.0-alpha3
; 


; Libraries
libraries[jquery_ui][download][type] = "get"
libraries[jquery_ui][destination] = "modules/contrib/jquery_ui"
libraries[jquery_ui][download][url] = "http://jquery-ui.googlecode.com/files/jquery.ui-1.6.zip"
libraries[jquery_ui][directory_name] = "jquery.ui"

