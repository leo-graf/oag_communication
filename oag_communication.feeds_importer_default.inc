<?php
/**
 * @file
 * oag_communication.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function oag_communication_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'discussion_post_by_email';
  $feeds_importer->config = array(
    'name' => 'Discussion post email importer',
    'description' => 'Imports Discussion Posts from Mailbox',
    'fetcher' => array(
      'plugin_key' => 'MailhandlerFetcher',
      'config' => array(
        'filter' => 'MailhandlerFiltersNodes',
      ),
    ),
    'parser' => array(
      'plugin_key' => 'MailhandlerParser',
      'config' => array(
        'available_commands' => 'status',
        'authenticate_plugin' => 'MailhandlerAuthenticateDefault',
        'extended_headers' => NULL,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => '0',
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'message_id',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'Blank source 1',
            'target' => 'title',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'body_html',
            'target' => 'body',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'attachments',
            'target' => 'field_oa_media:uri',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'authenticated_uid',
            'target' => 'uid',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'subject',
            'target' => 'og_group_ref:label',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '0',
        'input_format' => 'full_html',
        'skip_hash_check' => 0,
        'bundle' => 'oa_discussion_post',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '0',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['discussion_post_by_email'] = $feeds_importer;

  return $export;
}
