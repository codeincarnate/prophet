<?php

function prophet_admin_status() {
  global $cassandra_client;
  $keyspaces = $cassandra_client->describe_keyspaces();

  $header = array(t('Keyspace'), t('Replication Factor'), t('Operations'));
  $rows = array();
  foreach ($keyspaces as $keyspace) {
    $rows[] = array(
      $keyspace->name,
      $keyspace->replication_factor,
      'No operations yet',
    );
  }

  return theme('table', $header, $rows);
}