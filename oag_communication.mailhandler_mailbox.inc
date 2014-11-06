<?php
/**
 * @file
 * oag_communication.mailhandler_mailbox.inc
 */

/**
 * Implements hook_default_mailhandler_mailbox().
 */
function oag_communication_default_mailhandler_mailbox() {
  $export = array();

  $mailbox = new stdClass();
  $mailbox->disabled = FALSE; /* Edit this to true to make a default mailbox disabled initially */
  $mailbox->api_version = 2;
  $mailbox->mail = 'oag_communication_mailbox';
  $mailbox->admin_title = 'OA Grassroots Communication Mailbox';
  $mailbox->settings = array(
    'type' => 'imap',
    'folder' => 'INBOX',
    'domain' => '',
    'port' => '',
    'name' => '',
    'pass' => '',
    'extraimap' => '/ssl',
    'limit' => '0',
    'encoding' => 'UTF-8',
    'flag_after_read' => 0,
    'delete_after_read' => 1,
    'fromheader' => 'From',
    'security' => '0',
    'replies' => '1',
    'retrieve' => 'MailhandlerPhpImapRetrieve',
  );
  $export['oag_communication_mailbox'] = $mailbox;

  return $export;
}
