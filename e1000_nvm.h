/*******************************************************************************

  Intel(R) Gigabit Ethernet Linux driver
  Copyright(c) 2007-2012 Intel Corporation.

  This program is free software; you can redistribute it and/or modify it
  under the terms and conditions of the GNU General Public License,
  version 2, as published by the Free Software Foundation.

  This program is distributed in the hope it will be useful, but WITHOUT
  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
  FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
  more details.

  You should have received a copy of the GNU General Public License along with
  this program; if not, write to the Free Software Foundation, Inc.,
  51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.

  The full GNU General Public License is included in this distribution in
  the file called "COPYING".

  Contact Information:
  e1000-devel Mailing List <e1000-devel@lists.sourceforge.net>
  Intel Corporation, 5200 N.E. Elam Young Parkway, Hillsboro, OR 97124-6497

*******************************************************************************/

#ifndef _E1000_NVM_H_
#define _E1000_NVM_H_

void e1000_init_nvm_ops_generic(struct e1000_hw *hw);
s32  e1000_null_read_nvm(struct e1000_hw *hw, u16 a, u16 b, u16 *c);
void e1000_null_nvm_generic(struct e1000_hw *hw);
s32  e1000_null_led_default(struct e1000_hw *hw, u16 *data);
s32  e1000_null_write_nvm(struct e1000_hw *hw, u16 a, u16 b, u16 *c);
s32  e1000_acquire_nvm_generic(struct e1000_hw *hw);

s32  e1000_poll_eerd_eewr_done(struct e1000_hw *hw, int ee_reg);
s32  e1000_read_mac_addr_generic(struct e1000_hw *hw);
s32  e1000_read_pba_string_generic(struct e1000_hw *hw, u8 *pba_num,
				   u32 pba_num_size);
s32  e1000_read_pba_length_generic(struct e1000_hw *hw, u32 *pba_num_size);
s32  e1000_read_nvm_spi(struct e1000_hw *hw, u16 offset, u16 words, u16 *data);
s32  e1000_read_nvm_eerd(struct e1000_hw *hw, u16 offset, u16 words,
			 u16 *data);
s32  e1000_valid_led_default_generic(struct e1000_hw *hw, u16 *data);
s32  e1000_validate_nvm_checksum_generic(struct e1000_hw *hw);
s32  e1000_write_nvm_spi(struct e1000_hw *hw, u16 offset, u16 words,
			 u16 *data);
s32  e1000_update_nvm_checksum_generic(struct e1000_hw *hw);
void e1000_release_nvm_generic(struct e1000_hw *hw);

#define E1000_STM_OPCODE	0xDB00

s32 e1000_get_protected_block_size_generic(struct e1000_hw *hw,
			struct e1000_nvm_protected_block *block,
			u16 *eeprom_buffer, u32 eeprom_buffer_size);
s32 e1000_read_protected_block_generic(struct e1000_hw *hw,
				struct e1000_nvm_protected_block *block,
				u16 *eeprom_buffer, u32 eeprom_buffer_size);
s32 e1000_read_protected_blocks_generic(struct e1000_hw *hw,
				struct e1000_nvm_protected_block *blocks,
				u16 blocks_number, u16 *eeprom_buffer,
				u32 eeprom_buffer_size);
s32 e1000_write_protected_block_generic(struct e1000_hw *hw,
				struct e1000_nvm_protected_block *block,
				u16 *eeprom_buffer, u32 eeprom_buffer_size);
s32 e1000_write_protected_blocks_generic(struct e1000_hw *hw,
				struct e1000_nvm_protected_block *blocks,
				u16 blocks_number, u16 *eeprom_buffer,
				u32 eeprom_buffer_size);
s32 e1000_get_protected_blocks_from_table(struct e1000_hw *hw,
		struct e1000_nvm_protected_block *protected_blocks_table,
		u16 protected_blocks_table_size,
		struct e1000_nvm_protected_block *blocks, u16 *blocks_size,
		u32 block_type_mask, u16 *eeprom_buffer, u32 eeprom_size);
#endif
