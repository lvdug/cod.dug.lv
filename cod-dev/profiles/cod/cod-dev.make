; Conference Organizing Distribution dev snapshot makefile
; The purpose of this makefile is to make it easier for people to install
; the dev version of COD and its dependencies, including patches, before
; a new full release of the distribution is rolled.
api = 2
core = 7.x

projects[drupal] = 7.2
projects[drupal][download][type] = "git"
projects[drupal][download][url] = "http://git.drupal.org/project/drupal.git"
projects[drupal][download][revision] = "7.x"

projects[cod][type] = profile
projects[cod][download][type] = "git"
projects[cod][download][url] = "http://git.drupal.org/project/cod.git"
projects[cod][download][revision] = "7.x-1.x"