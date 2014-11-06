<?php
/**
 * @file
 * oag_communication.features.features_overrides.inc
 */

/**
 * Implements hook_features_override_default_overrides().
 */
function oag_communication_features_override_default_overrides() {
  // This code is only used for UI in features. Exported alters hooks do the magic.
  $overrides = array();

  // Exported overrides for: variable
  $overrides["variable.mailcomment_insert_reply_text.value"] = 0;

 return $overrides;
}
