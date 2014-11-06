<?php
/**
 * @file
 * oag_communication.feeds_tamper_default.inc
 */

/**
 * Implements hook_feeds_tamper_default().
 */
function oag_communication_feeds_tamper_default() {
  $export = array();

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'discussion_post_by_email-blank_source_1-find_replace_regex';
  $feeds_tamper->importer = 'discussion_post_by_email';
  $feeds_tamper->source = 'Blank source 1';
  $feeds_tamper->plugin_id = 'find_replace_regex';
  $feeds_tamper->settings = array(
    'find' => '/\\[.*?\\]/',
    'replace' => '',
    'limit' => '',
    'real_limit' => -1,
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Replace "[xyz]" with ""';
  $export['discussion_post_by_email-blank_source_1-find_replace_regex'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'discussion_post_by_email-blank_source_1-rewrite_with_subjekt';
  $feeds_tamper->importer = 'discussion_post_by_email';
  $feeds_tamper->source = 'Blank source 1';
  $feeds_tamper->plugin_id = 'rewrite';
  $feeds_tamper->settings = array(
    'text' => '[subject]',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Rewrite with [subject]';
  $export['discussion_post_by_email-blank_source_1-rewrite_with_subjekt'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'discussion_post_by_email-subject-find_replace_regex';
  $feeds_tamper->importer = 'discussion_post_by_email';
  $feeds_tamper->source = 'subject';
  $feeds_tamper->plugin_id = 'find_replace_regex';
  $feeds_tamper->settings = array(
    'find' => '/^(.*)\\[/',
    'replace' => '',
    'limit' => '',
    'real_limit' => -1,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Replace everything before "[" with ""';
  $export['discussion_post_by_email-subject-find_replace_regex'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'discussion_post_by_email-subject-find_replace_regex_2';
  $feeds_tamper->importer = 'discussion_post_by_email';
  $feeds_tamper->source = 'subject';
  $feeds_tamper->plugin_id = 'find_replace_regex';
  $feeds_tamper->settings = array(
    'find' => '/\\](.*)$/',
    'replace' => '',
    'limit' => '',
    'real_limit' => -1,
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Replace everything after "]" with ""';
  $export['discussion_post_by_email-subject-find_replace_regex_2'] = $feeds_tamper;

  return $export;
}
