<?php

/**
 * Form function, called by drupal_get_form()
 * in giftaid_menu().
 */
function giftaid_form($form, &$form_state) {
  $form['giftaid_value'] = array(
    '#type' => 'textfield',
    '#title' => t('Gift Aid percentage'),
    '#default_value' => variable_get('giftaid_value', 28),
    '#size' => 2,
    '#maxlength' => 2,
    '#description' => t('The percentage of a donation that you can claim as Gift Aid.'),
    '#required' => TRUE,
  );

  return system_settings_form($form);
}

function giftaid_form_validate($form, &$form_state) {
  $giftaid_value = $form_state['values']['giftaid_value'];
  if (!is_numeric($giftaid_value)) {
    form_set_error('giftaid_value', t('You must enter an integer for the basic rate.'));
  }
  elseif ($giftaid_value <= 0) {
    form_set_error('giftaid_value', t('The basic rate must be positive.'));
  }
}

