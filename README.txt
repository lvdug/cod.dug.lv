ABOUT
-----------------------------------------------------------------------------------------
The conference organizing install profile makes it easy to organize conferences 
through a website. 

FEATURES
-----------------------------------------------------------------------------------------
* Conference management 
    Create a new conference, with general time and location information, and registration
    options.  Site administrators can easily manage multiple conferences with a 
    custom interface.

* Refined registration
    A walkthrough registration process makes it easy for new or existing users 
    to register for a conference.
 
    If you wish to collect data from a person upon registration (such as meal preference)
    you can customize this using the webform module.  Collected webform data can then be 
    displayed in a table, or downloaded as a .csv file.

* Scheduling sessions is a breeze
    For each conference, organizers can propose and vote on sessions. A session is a topic
    of discussion for the conference, with a specific location and time slot for a day. 
    Once a session is scheduled into the conference, members can note if they are attending
    that specific session.
    
    Scheduled sessions are laid out in a calendar view for each day, with sessions marked
    in hourly blocks.  It can even handle multiple sessions scheduled at the same time, in
    different locations.
    
    On the schedule page users can check off which sessions they will be attending and their
    personalized schedule will then appear on their profile for others to see.
    
    
    
PREPARATION
-----------------------------------------------------------------------------------------

STEP 1...
  Download Drupal 5.x (http://drupal.org/download), and upload it on your server. 
  Don't install it yet, we first must prepare it for installation.  

  
  
STEP 2...
  Place the profile files in the directory 'profiles/cod'.
  
  
  
STEP 3...
  Download the following modules and put them in the directory 'profiles/cod/modules':
  Make sure that the module version is compatible with the Drupal version.
  
akismet                   http://drupal.org/project/akismet
bio                       http://drupal.org/project/bio
cck                       http://drupal.org/project/cck
chatroom                  http://drupal.org/project/chatroom
conference_organizing     http://drupal.org/project/conference_organizing
date                      http://drupal.org/project/conference_organizing
imagefield                http://drupal.org/project/imagefield
jstools                   http://drupal.org/project/jstools
link                      http://drupal.org/project/link
location                  http://drupal.org/project/location
logintoboggan             http://drupal.org/project/logintoboggan
moduleweight              http://drupal.org/project/moduleweight
og                        http://drupal.org/project/og
pathauto                  http://drupal.org/project/pathauto
pearwiki_filter           http://drupal.org/project/pearwiki_filter
tagadelic                 http://drupal.org/project/tagadelic
tagadelic_views           http://drupal.org/project/tagadelic_views
update_status             http://drupal.org/project/update_status
views                     http://drupal.org/project/views
views_fastsearch          http://drupal.org/project/views_fastsearch
vote_up_down              http://drupal.org/project/vote_up_down
votingapi                 http://drupal.org/project/votingapi
webform                   http://drupal.org/project/webform
wikitools                 http://drupal.org/project/wikitools



STEP 4...
  Download the custom theme and put it in the directory 'profiles/cod/themes'
  This theme works directly with the conference organizing module and profile.
  
cod_organizing            http://drupal.org/project/cod_organizing          



STEP 5...
  Create the directory 'files/pictures' within your Drupal directory.  This
  directory is used by modules and needs to exist before installation.
  
  
STEP 6...
  The pearwiki module requires you to install the pear wiki package.  Here is how to install it
  via the command line.

Go to the 'profiles/cod/modules/pearwiki_filter' directory and execute the command:

cvs -d :pserver:cvsread@cvs.php.net:/repository checkout -d Text pear/Text_Wiki/Text



INSTALLATION
-----------------------------------------------------------------------------------------
Make sure you have followed all the preparation steps, before installing Drupal.
If all your files are uploaded and in the right place, it's time to install Drupal.

Proceed with installation as you normally would. When asked for an installation 
profile, choose 'Conference Organizing'.

Please consult the handbooks (http://drupal.org/handbooks) if you need help installing Drupal.



CUSTOMIZATION AND POST-INSTALLATION
-----------------------------------------------------------------------------------------
Hopefully everything went smoothly and the install profile is running out of the box.
Most likely you will have to go and configure various settings before launching your site.

The most important configuration options are the access rules for anonymous users. If
you don't want anonymous users to be able to edit pages, go to

'administer > users > access control'


