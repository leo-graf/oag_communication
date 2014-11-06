<?php
/**
 * @file
 * oag_communication.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function oag_communication_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'default_ultimate_cron_job_feeds_cron';
  $strongarm->value = FALSE;
  $export['default_ultimate_cron_job_feeds_cron'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'default_ultimate_cron_job_oag_communication_import_discussion_post_by_email';
  $strongarm->value = FALSE;
  $export['default_ultimate_cron_job_oag_communication_import_discussion_post_by_email'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'default_ultimate_cron_job_oag_communication_import_discussion_reply_email_importer';
  $strongarm->value = FALSE;
  $export['default_ultimate_cron_job_oag_communication_import_discussion_reply_email_importer'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'mailcomment_alter_subjects';
  $strongarm->value = '0';
  $export['mailcomment_alter_subjects'] = $strongarm;

  return $export;
}
