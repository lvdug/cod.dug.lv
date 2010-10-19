; Conference Organizing Install Profile makefile

; Required version of Drupal core.
core = 6.x

; The following line is removed for the d.o hosted version, but allows this to run in drush make in general without the --drupal-org switch.
projects[drupal] = 6.19

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

projects[flag][subdir] = contrib
projects[flag][version] = 2.0-beta3
; http://drupal.org/node/846826
projects[flag][patch][] = "http://drupal.org/files/issues/flag_features_export.patch"

projects[features][subdir] = contrib

projects[filefield][subdir] = contrib

projects[globalredirect][subdir] = contrib

projects[imagefield][subdir] = contrib

projects[imageapi][subdir] = contrib

projects[imagecache][subdir] = contrib

projects[jquery_ui][subdir] = contrib

projects[markdown][subdir] = contrib

projects[pathauto][subdir] = contrib

projects[path_redirect][subdir] = contrib

projects[signup][subdir] = contrib

projects[token][subdir] = contrib

projects[uc_signup][subdir] = contrib

projects[ubercart][subdir] = contrib

projects[views][subdir] = contrib

; COD feature modules.
projects[cod_support][subdir] = features
projects[cod_support][version] = 1.0-alpha1



; Libraries
libraries[jquery_ui][download][type] = "get"
libraries[jquery_ui][destination] = "modules/contrib/jquery_ui"
libraries[jquery_ui][download][url] = "http://jquery-ui.googlecode.com/files/jquery.ui-1.6.zip"
libraries[jquery_ui][directory_name] = "jquery.ui"

