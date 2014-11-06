OpenAtrium Grassroots Communication
===================================
Part of the [Open Atrium Grassroots](http://github.com/leo-graf/oa_grassroots) installation profile.     

contrib_dependencies
--------------------
* [Feeds Tamper](https://www.drupal.org/project/feeds_tamper)
* [rules](https://www.drupal.org/project/rules)

feeds_importers
---------------
* discussion_post_by_email

feeds_tampers
-------------
* discussion_post_by_email-blank_source_1-find_replace_regex
* discussion_post_by_email-blank_source_1-rewrite_with_subjekt
* discussion_post_by_email-subject-find_replace_regex
* discussion_post_by_email-subject-find_replace_regex_2

mailhandler_mailboxes
---------------------
* oag_communication_mailbox
_config
------------
* rules_oag_communication_get_section_id
* rules_oag_communication_select_discussion_section

strongarm
---------
* default_ultimate_cron_job_feeds_cron
* default_ultimate_cron_job_oag_communication_import_discussion_post_by_email
* default_ultimate_cron_job_oag_communication_import_discussion_reply_email_importer
* mailcomment_alter_subjects
