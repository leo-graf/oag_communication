<?php
/**
 * @file
 * oag_communication.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function oag_communication_default_rules_configuration() {
  $items = array();
  $items['rules_oag_communication_get_section_id'] = entity_import('rules_config', '{ "rules_oag_communication_get_section_id" : {
      "LABEL" : "oag communication - get section id",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "OA Grassroots" ],
      "REQUIRES" : [ "rules", "feeds" ],
      "ON" : { "feeds_import_discussion_post_by_email" : [] },
      "DO" : [
        { "variable_add" : {
            "USING" : { "type" : "node", "value" : [ "node" ] },
            "PROVIDE" : { "variable_added" : { "post_imported" : "Hinzugef\\u00fcgter Post" } }
          }
        },
        { "entity_query" : {
            "USING" : {
              "type" : "node",
              "property" : "field_oa_section",
              "value" : "3",
              "limit" : [ "" ]
            },
            "PROVIDE" : { "entity_fetched" : { "entity_fetched" : "Abgerufenen Entit\\u00e4t" } }
          }
        },
        { "LOOP" : {
            "USING" : { "list" : [ "entity-fetched" ] },
            "ITEM" : { "list_item" : "Aktuelle Listenelement" },
            "DO" : [
              { "component_rules_oag_communication_select_discussion_section" : { "list_item" : [ "list_item" ], "post_imported" : [ "post_imported" ] } }
            ]
          }
        }
      ]
    }
  }');
  $items['rules_oag_communication_select_discussion_section'] = entity_import('rules_config', '{ "rules_oag_communication_select_discussion_section" : {
      "LABEL" : "oag communication - select discussion section",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "TAGS" : [ "OA Grassroots" ],
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : {
        "list_item" : { "label" : "Aktuelle Listenelement", "type" : "node" },
        "post_imported" : { "label" : "Hinzugef\\u00fcgter Post", "type" : "node" }
      },
      "IF" : [
        { "entity_has_field" : { "entity" : [ "list-item" ], "field" : "og_group_ref" } },
        { "entity_has_field" : { "entity" : [ "post-imported" ], "field" : "og_group_ref" } },
        { "entity_has_field" : { "entity" : [ "post-imported" ], "field" : "oa_section_ref" } },
        { "data_is" : {
            "data" : [ "list-item:og-group-ref" ],
            "value" : [ "post-imported:og-group-ref" ]
          }
        }
      ],
      "DO" : [
        { "data_set" : { "data" : [ "post-imported:oa-section-ref" ], "value" : [ "list-item" ] } }
      ]
    }
  }');
  return $items;
}
