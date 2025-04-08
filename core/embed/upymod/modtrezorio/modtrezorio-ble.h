/*
 * This file is part of the Trezor project, https://trezor.io/
 *
 * Copyright (c) SatoshiLabs
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <sys/sysevent.h>

/// package: trezorio.ble

///
/// def erase_bonds() -> bool:
///     """
///     Erases all BLE bonds
///     """
STATIC mp_obj_t mod_trezorio_BLE_erase_bonds(void) {
  ble_command_t cmd = {.cmd_type = BLE_ERASE_BONDS, .data_len = 0};
  return mp_obj_new_bool(ble_issue_command(&cmd));
}
STATIC MP_DEFINE_CONST_FUN_OBJ_0(mod_trezorio_BLE_erase_bonds_obj,
                                 mod_trezorio_BLE_erase_bonds);

/// def unpair() -> bool:
///     """
///     Erases bond for current connection, if any
///     """
STATIC mp_obj_t mod_trezorio_BLE_unpair(void) {
  ble_command_t cmd = {.cmd_type = BLE_UNPAIR, .data_len = 0};
  return mp_obj_new_bool(ble_issue_command(&cmd));
}
STATIC MP_DEFINE_CONST_FUN_OBJ_0(mod_trezorio_BLE_unpair_obj,
                                 mod_trezorio_BLE_unpair);

/// def start_comm() -> bool:
///     """
///     Start communication with BLE chip
///     """
STATIC mp_obj_t mod_trezorio_BLE_start_comm(void) {
  ble_start();
  return mp_const_none;
}
STATIC MP_DEFINE_CONST_FUN_OBJ_0(mod_trezorio_BLE_start_comm_obj,
                                 mod_trezorio_BLE_start_comm);

/// def start_advertising(whitelist: bool, name: str | None) -> bool:
///     """
///     Start advertising
///     """
STATIC mp_obj_t mod_trezorio_BLE_start_advertising(size_t n_args,
                                                   const mp_obj_t *args) {
  bool whitelist_bool = mp_obj_is_true(args[0]);

  mp_buffer_info_t name = {0};

  char *name_buf = NULL;
  int name_len = 0;

  if (n_args == 1 || !mp_get_buffer(args[1], &name, MP_BUFFER_READ)) {
    name_buf = MODEL_FULL_NAME;
    name_len = strlen(MODEL_FULL_NAME);
  } else {
    name_buf = name.buf;
    name_len = name.len;
  }

  ble_command_t cmd = {
      .cmd_type = whitelist_bool ? BLE_SWITCH_ON : BLE_PAIRING_MODE,
      .data_len = sizeof(ble_adv_start_cmd_data_t)};

  // get a minimum of the two lengths
  int len = name_len < BLE_ADV_NAME_LEN ? name_len : BLE_ADV_NAME_LEN;

  cmd.data.adv_start.static_mac = false;
  memcpy(cmd.data.adv_start.name, name_buf, len);

  return mp_obj_new_bool(ble_issue_command(&cmd));
}
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(
    mod_trezorio_BLE_start_advertising_obj, 1, 2,
    mod_trezorio_BLE_start_advertising);

/// def stop_advertising() -> bool:
///     """
///     Stop advertising
///     """
STATIC mp_obj_t mod_trezorio_BLE_stop_advertising(void) {
  ble_command_t cmd = {.cmd_type = BLE_SWITCH_OFF, .data_len = 0};
  return mp_obj_new_bool(ble_issue_command(&cmd));
}
STATIC MP_DEFINE_CONST_FUN_OBJ_0(mod_trezorio_BLE_stop_advertising_obj,
                                 mod_trezorio_BLE_stop_advertising);

/// def disconnect() -> bool:
///     """
///     Disconnect BLE
///     """
STATIC mp_obj_t mod_trezorio_BLE_disconnect(void) {
  ble_command_t cmd = {.cmd_type = BLE_DISCONNECT, .data_len = 0};
  return mp_obj_new_bool(ble_issue_command(&cmd));
}
STATIC MP_DEFINE_CONST_FUN_OBJ_0(mod_trezorio_BLE_disconnect_obj,
                                 mod_trezorio_BLE_disconnect);

/// def peer_count() -> int:
///     """
///     Get peer count (number of bonded devices)
///     """
STATIC mp_obj_t mod_trezorio_BLE_peer_count(void) {
  ble_state_t state;
  ble_get_state(&state);
  return MP_OBJ_NEW_SMALL_INT(state.peer_count);
}
STATIC MP_DEFINE_CONST_FUN_OBJ_0(mod_trezorio_BLE_peer_count_obj,
                                 mod_trezorio_BLE_peer_count);

const size_t CODE_LEN = 6;
static bool encode_pairing_code(mp_obj_t obj, uint8_t *outbuf) {
  mp_int_t code = mp_obj_get_int(obj);
  if (code < 0 || code > 999999) {
    return false;
  }
  for (size_t i = 0; i < CODE_LEN; i++) {
    outbuf[CODE_LEN - i - 1] = '0' + (code % 10);
    code /= 10;
  }
  return true;
}

/// def allow_pairing(code: int) -> bool:
///     """
///     Accept BLE pairing request. Code must match the one received with
///     BLE_PAIRING_REQUEST event.
///     """
STATIC mp_obj_t mod_trezorio_BLE_allow_pairing(mp_obj_t code) {
  ble_command_t cmd = {.cmd_type = BLE_ALLOW_PAIRING, .data_len = CODE_LEN};
  if (!encode_pairing_code(code, cmd.data.raw)) {
    return mp_const_false;
  }
  return mp_obj_new_bool(ble_issue_command(&cmd));
}
STATIC MP_DEFINE_CONST_FUN_OBJ_1(mod_trezorio_BLE_allow_pairing_obj,
                                 mod_trezorio_BLE_allow_pairing);

/// def reject_pairing() -> bool:
///     """
///     Reject BLE pairing request
///     """
STATIC mp_obj_t mod_trezorio_BLE_reject_pairing(void) {
  ble_command_t cmd = {.cmd_type = BLE_REJECT_PAIRING, .data_len = 0};
  return mp_obj_new_bool(ble_issue_command(&cmd));
}
STATIC MP_DEFINE_CONST_FUN_OBJ_0(mod_trezorio_BLE_reject_pairing_obj,
                                 mod_trezorio_BLE_reject_pairing);

/// class BleInterface:
///     """
///     BLE interface wrapper.
///     """
typedef struct _mp_obj_BleInterface_t {
  mp_obj_base_t base;
} mp_obj_BleInterface_t;

/// def __init__(
///     self,
/// ) -> None:
///     """
///     Initialize BLE interface.
///     """
STATIC mp_obj_t mod_trezorio_BleInterface_make_new(const mp_obj_type_t *type,
                                                   size_t n_args, size_t n_kw,
                                                   const mp_obj_t *args) {
  mp_arg_check_num(n_args, n_kw, 0, 0, false);
  mp_obj_BleInterface_t *o = mp_obj_malloc(mp_obj_BleInterface_t, type);
  return MP_OBJ_FROM_PTR(o);
}

/// def iface_num(self) -> int:
///     """
///     Returns the configured number of this interface.
///     """
STATIC mp_obj_t mod_trezorio_BleInterface_iface_num(mp_obj_t self) {
  return MP_OBJ_NEW_SMALL_INT(SYSHANDLE_BLE_IFACE_0);
}
STATIC MP_DEFINE_CONST_FUN_OBJ_1(mod_trezorio_BleInterface_iface_num_obj,
                                 mod_trezorio_BleInterface_iface_num);

/// def write(self, msg: bytes) -> int:
///     """
///     Sends message over BLE
///     """
STATIC mp_obj_t mod_trezorio_BleInterface_write(mp_obj_t self, mp_obj_t msg) {
  mp_buffer_info_t buf = {0};
  mp_get_buffer_raise(msg, &buf, MP_BUFFER_READ);
  bool success = ble_write(buf.buf, buf.len);
  if (success) {
    return MP_OBJ_NEW_SMALL_INT(buf.len);
  } else {
    return MP_OBJ_NEW_SMALL_INT(-1);
  }
}
STATIC MP_DEFINE_CONST_FUN_OBJ_2(mod_trezorio_BleInterface_write_obj,
                                 mod_trezorio_BleInterface_write);

/// def read(self, buf: bytearray, offset: int = 0) -> int:
///     """
///     Reads message using BLE (device).
///     """
STATIC mp_obj_t mod_trezorio_BleInterface_read(size_t n_args,
                                               const mp_obj_t *args) {
  mp_buffer_info_t buf = {0};
  mp_get_buffer_raise(args[1], &buf, MP_BUFFER_WRITE);

  int offset = 0;
  if (n_args >= 2) {
    offset = mp_obj_get_int(args[2]);
  }

  if (offset < 0) {
    mp_raise_ValueError("Negative offset not allowed");
  }

  if (offset > buf.len) {
    mp_raise_ValueError("Offset out of bounds");
  }

  uint32_t buffer_space = buf.len - offset;

  if (buffer_space < BLE_RX_PACKET_SIZE) {
    mp_raise_ValueError("Buffer too small");
  }

  uint32_t r = ble_read(&((uint8_t *)buf.buf)[offset], BLE_RX_PACKET_SIZE);

  if (r != BLE_RX_PACKET_SIZE) {
    mp_raise_msg(&mp_type_RuntimeError, "Unexpected read length");
  }

  return MP_OBJ_NEW_SMALL_INT(r);
}
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(mod_trezorio_BleInterface_read_obj,
                                           2, 3,
                                           mod_trezorio_BleInterface_read);

/// RX_PACKET_LEN: int
/// """Length of one BLE RX packet."""

/// TX_PACKET_LEN: int
/// """Length of one BLE TX packet."""

STATIC const mp_rom_map_elem_t mod_trezorio_BleInterface_locals_dict_table[] = {
    {MP_ROM_QSTR(MP_QSTR_iface_num),
     MP_ROM_PTR(&mod_trezorio_BleInterface_iface_num_obj)},
    {MP_ROM_QSTR(MP_QSTR_write),
     MP_ROM_PTR(&mod_trezorio_BleInterface_write_obj)},
    {MP_ROM_QSTR(MP_QSTR_read),
     MP_ROM_PTR(&mod_trezorio_BleInterface_read_obj)},
    {MP_ROM_QSTR(MP_QSTR_RX_PACKET_LEN), MP_ROM_INT(BLE_RX_PACKET_SIZE)},
    {MP_ROM_QSTR(MP_QSTR_TX_PACKET_LEN), MP_ROM_INT(BLE_TX_PACKET_SIZE)},
};
STATIC MP_DEFINE_CONST_DICT(mod_trezorio_BleInterface_locals_dict,
                            mod_trezorio_BleInterface_locals_dict_table);

STATIC const mp_obj_type_t mod_trezorio_BleInterface_type = {
    {&mp_type_type},
    .name = MP_QSTR_BleInterface,
    .make_new = mod_trezorio_BleInterface_make_new,
    .locals_dict = (void *)&mod_trezorio_BleInterface_locals_dict,
};

STATIC const mp_rom_map_elem_t mod_trezorio_BLE_globals_table[] = {
    {MP_ROM_QSTR(MP_QSTR___name__), MP_ROM_QSTR(MP_QSTR_ble)},
    {MP_ROM_QSTR(MP_QSTR_erase_bonds),
     MP_ROM_PTR(&mod_trezorio_BLE_erase_bonds_obj)},
    {MP_ROM_QSTR(MP_QSTR_unpair), MP_ROM_PTR(&mod_trezorio_BLE_unpair_obj)},
    {MP_ROM_QSTR(MP_QSTR_start_comm),
     MP_ROM_PTR(&mod_trezorio_BLE_start_comm_obj)},
    {MP_ROM_QSTR(MP_QSTR_start_advertising),
     MP_ROM_PTR(&mod_trezorio_BLE_start_advertising_obj)},
    {MP_ROM_QSTR(MP_QSTR_stop_advertising),
     MP_ROM_PTR(&mod_trezorio_BLE_stop_advertising_obj)},
    {MP_ROM_QSTR(MP_QSTR_disconnect),
     MP_ROM_PTR(&mod_trezorio_BLE_disconnect_obj)},
    {MP_ROM_QSTR(MP_QSTR_peer_count),
     MP_ROM_PTR(&mod_trezorio_BLE_peer_count_obj)},
    {MP_ROM_QSTR(MP_QSTR_allow_pairing),
     MP_ROM_PTR(&mod_trezorio_BLE_allow_pairing_obj)},
    {MP_ROM_QSTR(MP_QSTR_reject_pairing),
     MP_ROM_PTR(&mod_trezorio_BLE_reject_pairing_obj)},
    {MP_ROM_QSTR(MP_QSTR_BleInterface),
     MP_ROM_PTR(&mod_trezorio_BleInterface_type)},
};
STATIC MP_DEFINE_CONST_DICT(mod_trezorio_BLE_globals,
                            mod_trezorio_BLE_globals_table);

STATIC const mp_obj_module_t mod_trezorio_BLE_module = {
    .base = {&mp_type_module},
    .globals = (mp_obj_dict_t *)&mod_trezorio_BLE_globals};
