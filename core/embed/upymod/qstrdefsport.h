// generated from qstrdefsport.h.mako
// (by running `make templates` in `core`)
// do not edit manually!
// fmt: off

#error This header should not be part of the build, its purpose is only to add missed Qstrings

// explanation:
// uPy collects string literals and symbol names from all frozen modules, and
// converts them to qstrings for certain usages. In particular, it appears that
// qualified names of modules in sys.modules must be qstrings. However, the
// collection process is imperfect. If `apps.common.mnemonic` is always imported
// as `from ..common import mnemonic`, the string "apps.common.mnemonic" never
// appears in source code, is never collected, but then is generated and
// interned at runtime. A similar thing happens in reverse: if module
// `storage.cache` is always imported as this name, then "storage.cache" is
// collected but neither "storage" nor "cache" alone. Which is a problem,
// because "cache" is a symbol that is added to `storage`'s dict.
//
// We need to avoid run-time interning as much as possible, because it creates
// uncollectable garbage in the GC arena.

Q(AmountUnit)
Q(BackupAvailability)
Q(BackupType)
Q(BootCommand)
Q(ButtonRequestType)
Q(Capability)
Q(DecredStakingSpendType)
Q(DisplayRotation)
Q(FailureType)
Q(HomescreenFormat)
Q(InputScriptType)
Q(MessageType)
Q(MultisigPubkeysOrder)
Q(OutputScriptType)
Q(PinMatrixRequestType)
Q(RecoveryDeviceInputMethod)
Q(RecoveryStatus)
Q(RecoveryType)
Q(RequestType)
Q(SafetyCheckLevel)
Q(SdProtectOperationType)
Q(WordRequestType)
Q(address_mac)
Q(address_type)
Q(addresses)
Q(apply_flags)
Q(apply_settings)
Q(approvers)
Q(apps)
Q(apps.base)
Q(apps.benchmark)
Q(apps.benchmark.benchmark)
Q(apps.benchmark.benchmarks)
Q(apps.benchmark.cipher_benchmark)
Q(apps.benchmark.common)
Q(apps.benchmark.curve_benchmark)
Q(apps.benchmark.hash_benchmark)
Q(apps.benchmark.list_names)
Q(apps.benchmark.run)
Q(apps.bitcoin)
Q(apps.bitcoin.addresses)
Q(apps.bitcoin.authorization)
Q(apps.bitcoin.authorize_coinjoin)
Q(apps.bitcoin.common)
Q(apps.bitcoin.get_address)
Q(apps.bitcoin.get_ownership_id)
Q(apps.bitcoin.get_ownership_proof)
Q(apps.bitcoin.get_public_key)
Q(apps.bitcoin.keychain)
Q(apps.bitcoin.multisig)
Q(apps.bitcoin.ownership)
Q(apps.bitcoin.readers)
Q(apps.bitcoin.scripts)
Q(apps.bitcoin.scripts_decred)
Q(apps.bitcoin.sign_message)
Q(apps.bitcoin.sign_tx)
Q(apps.bitcoin.sign_tx.approvers)
Q(apps.bitcoin.sign_tx.bitcoin)
Q(apps.bitcoin.sign_tx.bitcoinlike)
Q(apps.bitcoin.sign_tx.change_detector)
Q(apps.bitcoin.sign_tx.decred)
Q(apps.bitcoin.sign_tx.helpers)
Q(apps.bitcoin.sign_tx.layout)
Q(apps.bitcoin.sign_tx.matchcheck)
Q(apps.bitcoin.sign_tx.omni)
Q(apps.bitcoin.sign_tx.payment_request)
Q(apps.bitcoin.sign_tx.progress)
Q(apps.bitcoin.sign_tx.sig_hasher)
Q(apps.bitcoin.sign_tx.tx_info)
Q(apps.bitcoin.sign_tx.tx_weight)
Q(apps.bitcoin.verification)
Q(apps.bitcoin.verify_message)
Q(apps.bitcoin.writers)
Q(apps.common)
Q(apps.common.address_mac)
Q(apps.common.address_type)
Q(apps.common.authorization)
Q(apps.common.backup)
Q(apps.common.backup_types)
Q(apps.common.cache)
Q(apps.common.cbor)
Q(apps.common.coininfo)
Q(apps.common.coins)
Q(apps.common.keychain)
Q(apps.common.passphrase)
Q(apps.common.paths)
Q(apps.common.readers)
Q(apps.common.request_pin)
Q(apps.common.safety_checks)
Q(apps.common.sdcard)
Q(apps.common.seed)
Q(apps.common.signverify)
Q(apps.common.writers)
Q(apps.homescreen)
Q(apps.management)
Q(apps.management.apply_flags)
Q(apps.management.apply_settings)
Q(apps.management.authenticate_device)
Q(apps.management.backup_device)
Q(apps.management.ble.unpair)
Q(apps.management.change_language)
Q(apps.management.change_pin)
Q(apps.management.change_wipe_code)
Q(apps.management.get_next_u2f_counter)
Q(apps.management.get_nonce)
Q(apps.management.reboot_to_bootloader)
Q(apps.management.recovery_device)
Q(apps.management.recovery_device.homescreen)
Q(apps.management.recovery_device.layout)
Q(apps.management.recovery_device.recover)
Q(apps.management.recovery_device.word_validity)
Q(apps.management.reset_device)
Q(apps.management.reset_device.layout)
Q(apps.management.sd_protect)
Q(apps.management.set_brightness)
Q(apps.management.set_u2f_counter)
Q(apps.management.show_tutorial)
Q(apps.management.wipe_device)
Q(apps.misc)
Q(apps.misc.cipher_key_value)
Q(apps.misc.get_ecdh_session_key)
Q(apps.misc.get_entropy)
Q(apps.misc.get_firmware_hash)
Q(apps.misc.sign_identity)
Q(apps.nostr)
Q(apps.nostr.get_pubkey)
Q(apps.nostr.sign_event)
Q(apps.workflow_handlers)
Q(authenticate_device)
Q(authorization)
Q(authorize_coinjoin)
Q(backup)
Q(backup_device)
Q(backup_types)
Q(base)
Q(base32)
Q(base58)
Q(bech32)
Q(benchmark)
Q(benchmarks)
Q(bitcoin)
Q(bitcoinlike)
Q(bolt)
Q(boot)
Q(cache)
Q(cache_codec)
Q(cache_common)
Q(caesar)
Q(cashaddr)
Q(cbor)
Q(change_detector)
Q(change_language)
Q(change_pin)
Q(change_wipe_code)
Q(cipher_benchmark)
Q(cipher_key_value)
Q(codec)
Q(codec_context)
Q(codec_v1)
Q(coininfo)
Q(coins)
Q(common)
Q(context)
Q(cosi)
Q(crypto)
Q(curve)
Q(curve_benchmark)
Q(decred)
Q(delizia)
Q(der)
Q(device)
Q(enums)
Q(errors)
Q(fido)
Q(fido2)
Q(get_address)
Q(get_ecdh_session_key)
Q(get_entropy)
Q(get_firmware_hash)
Q(get_next_u2f_counter)
Q(get_nonce)
Q(get_ownership_id)
Q(get_ownership_proof)
Q(get_pubkey)
Q(get_public_key)
Q(hash_benchmark)
Q(hashlib)
Q(helpers)
Q(homescreen)
Q(keychain)
Q(layout)
Q(layouts)
Q(list_names)
Q(log)
Q(loop)
Q(main)
Q(management)
Q(matchcheck)
Q(message_handler)
Q(messages)
Q(misc)
Q(multisig)
Q(nostr)
Q(omni)
Q(ownership)
Q(passphrase)
Q(paths)
Q(payment_request)
Q(pin)
Q(progress)
Q(protobuf)
Q(protocol_common)
Q(readers)
Q(reboot_to_bootloader)
Q(recover)
Q(recovery)
Q(recovery_device)
Q(recovery_shares)
Q(request_pin)
Q(reset)
Q(reset_device)
Q(resident_credentials)
Q(rlp)
Q(run)
Q(safety_checks)
Q(scripts)
Q(scripts_decred)
Q(sd_protect)
Q(sd_salt)
Q(sdcard)
Q(seed)
Q(session)
Q(set_brightness)
Q(set_u2f_counter)
Q(show_tutorial)
Q(sig_hasher)
Q(sign_event)
Q(sign_identity)
Q(sign_message)
Q(sign_tx)
Q(signverify)
Q(slip39)
Q(storage)
Q(storage.cache)
Q(storage.cache_codec)
Q(storage.cache_common)
Q(storage.common)
Q(storage.device)
Q(storage.fido2)
Q(storage.recovery)
Q(storage.recovery_shares)
Q(storage.resident_credentials)
Q(storage.sd_salt)
Q(strings)
Q(trezor)
Q(trezor.crypto)
Q(trezor.crypto.base32)
Q(trezor.crypto.base58)
Q(trezor.crypto.bech32)
Q(trezor.crypto.cashaddr)
Q(trezor.crypto.cosi)
Q(trezor.crypto.curve)
Q(trezor.crypto.der)
Q(trezor.crypto.hashlib)
Q(trezor.crypto.rlp)
Q(trezor.crypto.scripts)
Q(trezor.crypto.slip39)
Q(trezor.enums)
Q(trezor.enums.AmountUnit)
Q(trezor.enums.BackupAvailability)
Q(trezor.enums.BackupType)
Q(trezor.enums.BootCommand)
Q(trezor.enums.ButtonRequestType)
Q(trezor.enums.Capability)
Q(trezor.enums.DecredStakingSpendType)
Q(trezor.enums.DisplayRotation)
Q(trezor.enums.FailureType)
Q(trezor.enums.HomescreenFormat)
Q(trezor.enums.InputScriptType)
Q(trezor.enums.MessageType)
Q(trezor.enums.MultisigPubkeysOrder)
Q(trezor.enums.OutputScriptType)
Q(trezor.enums.PinMatrixRequestType)
Q(trezor.enums.RecoveryDeviceInputMethod)
Q(trezor.enums.RecoveryStatus)
Q(trezor.enums.RecoveryType)
Q(trezor.enums.RequestType)
Q(trezor.enums.SafetyCheckLevel)
Q(trezor.enums.SdProtectOperationType)
Q(trezor.enums.WordRequestType)
Q(trezor.errors)
Q(trezor.log)
Q(trezor.loop)
Q(trezor.messages)
Q(trezor.pin)
Q(trezor.protobuf)
Q(trezor.sdcard)
Q(trezor.strings)
Q(trezor.ui)
Q(trezor.ui.layouts)
Q(trezor.ui.layouts.bolt)
Q(trezor.ui.layouts.bolt.fido)
Q(trezor.ui.layouts.bolt.recovery)
Q(trezor.ui.layouts.bolt.reset)
Q(trezor.ui.layouts.caesar)
Q(trezor.ui.layouts.caesar.fido)
Q(trezor.ui.layouts.caesar.recovery)
Q(trezor.ui.layouts.caesar.reset)
Q(trezor.ui.layouts.common)
Q(trezor.ui.layouts.delizia)
Q(trezor.ui.layouts.delizia.fido)
Q(trezor.ui.layouts.delizia.recovery)
Q(trezor.ui.layouts.delizia.reset)
Q(trezor.ui.layouts.fido)
Q(trezor.ui.layouts.homescreen)
Q(trezor.ui.layouts.progress)
Q(trezor.ui.layouts.recovery)
Q(trezor.ui.layouts.reset)
Q(trezor.utils)
Q(trezor.wire)
Q(trezor.wire.codec)
Q(trezor.wire.codec.codec_context)
Q(trezor.wire.codec.codec_v1)
Q(trezor.wire.context)
Q(trezor.wire.errors)
Q(trezor.wire.message_handler)
Q(trezor.wire.protocol_common)
Q(trezor.workflow)
Q(tx_info)
Q(tx_weight)
Q(typing)
Q(ui)
Q(unpair)
Q(usb)
Q(utils)
Q(verification)
Q(verify_message)
Q(wipe_device)
Q(wire)
Q(word_validity)
Q(workflow)
Q(workflow_handlers)
Q(writers)

#if USE_THP
Q(apps.thp)
Q(apps.thp.credential_manager)
Q(credential_manager)
Q(thp)
#endif

#if !BITCOIN_ONLY
Q(BinanceOrderSide)
Q(BinanceOrderType)
Q(BinanceTimeInForce)
Q(CardanoAddressType)
Q(CardanoCVoteRegistrationFormat)
Q(CardanoCertificateType)
Q(CardanoDRepType)
Q(CardanoDerivationType)
Q(CardanoNativeScriptHashDisplayFormat)
Q(CardanoNativeScriptType)
Q(CardanoPoolRelayType)
Q(CardanoTxAuxiliaryDataSupplementType)
Q(CardanoTxOutputSerializationFormat)
Q(CardanoTxSigningMode)
Q(CardanoTxWitnessType)
Q(EthereumDataType)
Q(EthereumDefinitionType)
Q(MoneroNetworkType)
Q(NEMImportanceTransferMode)
Q(NEMModificationType)
Q(NEMMosaicLevy)
Q(NEMSupplyChangeType)
Q(StellarAssetType)
Q(StellarMemoType)
Q(StellarSignerType)
Q(TezosBallotType)
Q(TezosContractType)
Q(account_path_check)
Q(actions)
Q(add_resident_credential)
Q(addresses)
Q(apps.binance)
Q(apps.binance.get_address)
Q(apps.binance.get_public_key)
Q(apps.binance.helpers)
Q(apps.binance.layout)
Q(apps.binance.sign_tx)
Q(apps.bitcoin.sign_tx.zcash_v4)
Q(apps.cardano)
Q(apps.cardano.addresses)
Q(apps.cardano.auxiliary_data)
Q(apps.cardano.byron_addresses)
Q(apps.cardano.certificates)
Q(apps.cardano.get_address)
Q(apps.cardano.get_native_script_hash)
Q(apps.cardano.get_public_key)
Q(apps.cardano.helpers)
Q(apps.cardano.helpers.account_path_check)
Q(apps.cardano.helpers.bech32)
Q(apps.cardano.helpers.credential)
Q(apps.cardano.helpers.hash_builder_collection)
Q(apps.cardano.helpers.network_ids)
Q(apps.cardano.helpers.paths)
Q(apps.cardano.helpers.protocol_magics)
Q(apps.cardano.helpers.utils)
Q(apps.cardano.layout)
Q(apps.cardano.native_script)
Q(apps.cardano.seed)
Q(apps.cardano.sign_tx)
Q(apps.cardano.sign_tx.multisig_signer)
Q(apps.cardano.sign_tx.ordinary_signer)
Q(apps.cardano.sign_tx.plutus_signer)
Q(apps.cardano.sign_tx.pool_owner_signer)
Q(apps.cardano.sign_tx.signer)
Q(apps.common.mnemonic)
Q(apps.eos)
Q(apps.eos.actions)
Q(apps.eos.actions.layout)
Q(apps.eos.get_public_key)
Q(apps.eos.helpers)
Q(apps.eos.layout)
Q(apps.eos.sign_tx)
Q(apps.eos.writers)
Q(apps.ethereum)
Q(apps.ethereum.definitions)
Q(apps.ethereum.definitions_constants)
Q(apps.ethereum.get_address)
Q(apps.ethereum.get_public_key)
Q(apps.ethereum.helpers)
Q(apps.ethereum.keychain)
Q(apps.ethereum.layout)
Q(apps.ethereum.networks)
Q(apps.ethereum.sign_message)
Q(apps.ethereum.sign_tx)
Q(apps.ethereum.sign_tx_eip1559)
Q(apps.ethereum.sign_typed_data)
Q(apps.ethereum.staking_tx_constants)
Q(apps.ethereum.tokens)
Q(apps.ethereum.verify_message)
Q(apps.monero)
Q(apps.monero.diag)
Q(apps.monero.get_address)
Q(apps.monero.get_tx_keys)
Q(apps.monero.get_watch_only)
Q(apps.monero.key_image_sync)
Q(apps.monero.layout)
Q(apps.monero.live_refresh)
Q(apps.monero.misc)
Q(apps.monero.sign_tx)
Q(apps.monero.signing)
Q(apps.monero.signing.offloading_keys)
Q(apps.monero.signing.state)
Q(apps.monero.signing.step_01_init_transaction)
Q(apps.monero.signing.step_02_set_input)
Q(apps.monero.signing.step_04_input_vini)
Q(apps.monero.signing.step_05_all_inputs_set)
Q(apps.monero.signing.step_06_set_output)
Q(apps.monero.signing.step_07_all_outputs_set)
Q(apps.monero.signing.step_09_sign_input)
Q(apps.monero.signing.step_10_sign_final)
Q(apps.monero.xmr)
Q(apps.monero.xmr.addresses)
Q(apps.monero.xmr.bulletproof)
Q(apps.monero.xmr.chacha_poly)
Q(apps.monero.xmr.clsag)
Q(apps.monero.xmr.credentials)
Q(apps.monero.xmr.crypto_helpers)
Q(apps.monero.xmr.keccak_hasher)
Q(apps.monero.xmr.key_image)
Q(apps.monero.xmr.mlsag_hasher)
Q(apps.monero.xmr.monero)
Q(apps.monero.xmr.networks)
Q(apps.monero.xmr.range_signatures)
Q(apps.monero.xmr.serialize)
Q(apps.monero.xmr.serialize.base_types)
Q(apps.monero.xmr.serialize.int_serialize)
Q(apps.monero.xmr.serialize.message_types)
Q(apps.monero.xmr.serialize.readwriter)
Q(apps.monero.xmr.serialize_messages.base)
Q(apps.monero.xmr.serialize_messages.tx_ct_key)
Q(apps.monero.xmr.serialize_messages.tx_ecdh)
Q(apps.monero.xmr.serialize_messages.tx_prefix)
Q(apps.monero.xmr.serialize_messages.tx_rsig_bulletproof)
Q(apps.nem)
Q(apps.nem.get_address)
Q(apps.nem.helpers)
Q(apps.nem.layout)
Q(apps.nem.mosaic)
Q(apps.nem.mosaic.helpers)
Q(apps.nem.mosaic.layout)
Q(apps.nem.mosaic.nem_mosaics)
Q(apps.nem.mosaic.serialize)
Q(apps.nem.multisig)
Q(apps.nem.multisig.layout)
Q(apps.nem.multisig.serialize)
Q(apps.nem.namespace)
Q(apps.nem.namespace.layout)
Q(apps.nem.namespace.serialize)
Q(apps.nem.sign_tx)
Q(apps.nem.transfer)
Q(apps.nem.transfer.layout)
Q(apps.nem.transfer.serialize)
Q(apps.nem.validators)
Q(apps.nem.writers)
Q(apps.ripple)
Q(apps.ripple.base58_ripple)
Q(apps.ripple.get_address)
Q(apps.ripple.helpers)
Q(apps.ripple.layout)
Q(apps.ripple.serialize)
Q(apps.ripple.sign_tx)
Q(apps.solana)
Q(apps.solana.constants)
Q(apps.solana.format)
Q(apps.solana.get_address)
Q(apps.solana.get_public_key)
Q(apps.solana.layout)
Q(apps.solana.predefined_transaction)
Q(apps.solana.sign_tx)
Q(apps.solana.token_account)
Q(apps.solana.transaction)
Q(apps.solana.transaction.instruction)
Q(apps.solana.transaction.instructions)
Q(apps.solana.transaction.parse)
Q(apps.solana.types)
Q(apps.stellar)
Q(apps.stellar.consts)
Q(apps.stellar.get_address)
Q(apps.stellar.helpers)
Q(apps.stellar.layout)
Q(apps.stellar.operations)
Q(apps.stellar.operations.layout)
Q(apps.stellar.operations.serialize)
Q(apps.stellar.sign_tx)
Q(apps.stellar.writers)
Q(apps.tezos)
Q(apps.tezos.get_address)
Q(apps.tezos.get_public_key)
Q(apps.tezos.helpers)
Q(apps.tezos.layout)
Q(apps.tezos.sign_tx)
Q(apps.webauthn)
Q(apps.webauthn.add_resident_credential)
Q(apps.webauthn.common)
Q(apps.webauthn.credential)
Q(apps.webauthn.fido2)
Q(apps.webauthn.knownapps)
Q(apps.webauthn.list_resident_credentials)
Q(apps.webauthn.remove_resident_credential)
Q(apps.webauthn.resident_credentials)
Q(apps.zcash)
Q(apps.zcash.f4jumble)
Q(apps.zcash.hasher)
Q(apps.zcash.signer)
Q(apps.zcash.unified_addresses)
Q(auxiliary_data)
Q(base)
Q(base58_ripple)
Q(base_types)
Q(bech32)
Q(binance)
Q(bulletproof)
Q(byron_addresses)
Q(cardano)
Q(certificates)
Q(chacha_poly)
Q(clsag)
Q(common)
Q(constants)
Q(consts)
Q(credential)
Q(credentials)
Q(crypto_helpers)
Q(definitions)
Q(definitions_constants)
Q(diag)
Q(eos)
Q(ethereum)
Q(f4jumble)
Q(fido2)
Q(format)
Q(get_address)
Q(get_native_script_hash)
Q(get_public_key)
Q(get_tx_keys)
Q(get_watch_only)
Q(hash_builder_collection)
Q(hasher)
Q(helpers)
Q(instruction)
Q(instructions)
Q(int_serialize)
Q(keccak_hasher)
Q(key_image)
Q(key_image_sync)
Q(keychain)
Q(knownapps)
Q(layout)
Q(list_resident_credentials)
Q(live_refresh)
Q(message_types)
Q(misc)
Q(mlsag_hasher)
Q(mnemonic)
Q(monero)
Q(mosaic)
Q(multisig)
Q(multisig_signer)
Q(namespace)
Q(native_script)
Q(nem)
Q(nem_mosaics)
Q(network_ids)
Q(networks)
Q(offloading_keys)
Q(operations)
Q(ordinary_signer)
Q(parse)
Q(paths)
Q(plutus_signer)
Q(pool_owner_signer)
Q(predefined_transaction)
Q(protocol_magics)
Q(range_signatures)
Q(readwriter)
Q(remove_resident_credential)
Q(resident_credentials)
Q(ripple)
Q(seed)
Q(serialize)
Q(sign_message)
Q(sign_tx)
Q(sign_tx_eip1559)
Q(sign_typed_data)
Q(signer)
Q(signing)
Q(solana)
Q(staking_tx_constants)
Q(state)
Q(stellar)
Q(step_01_init_transaction)
Q(step_02_set_input)
Q(step_04_input_vini)
Q(step_05_all_inputs_set)
Q(step_06_set_output)
Q(step_07_all_outputs_set)
Q(step_09_sign_input)
Q(step_10_sign_final)
Q(tezos)
Q(token_account)
Q(tokens)
Q(transaction)
Q(transfer)
Q(trezor.enums.BinanceOrderSide)
Q(trezor.enums.BinanceOrderType)
Q(trezor.enums.BinanceTimeInForce)
Q(trezor.enums.CardanoAddressType)
Q(trezor.enums.CardanoCVoteRegistrationFormat)
Q(trezor.enums.CardanoCertificateType)
Q(trezor.enums.CardanoDRepType)
Q(trezor.enums.CardanoDerivationType)
Q(trezor.enums.CardanoNativeScriptHashDisplayFormat)
Q(trezor.enums.CardanoNativeScriptType)
Q(trezor.enums.CardanoPoolRelayType)
Q(trezor.enums.CardanoTxAuxiliaryDataSupplementType)
Q(trezor.enums.CardanoTxOutputSerializationFormat)
Q(trezor.enums.CardanoTxSigningMode)
Q(trezor.enums.CardanoTxWitnessType)
Q(trezor.enums.EthereumDataType)
Q(trezor.enums.EthereumDefinitionType)
Q(trezor.enums.MoneroNetworkType)
Q(trezor.enums.NEMImportanceTransferMode)
Q(trezor.enums.NEMModificationType)
Q(trezor.enums.NEMMosaicLevy)
Q(trezor.enums.NEMSupplyChangeType)
Q(trezor.enums.StellarAssetType)
Q(trezor.enums.StellarMemoType)
Q(trezor.enums.StellarSignerType)
Q(trezor.enums.TezosBallotType)
Q(trezor.enums.TezosContractType)
Q(tx_ct_key)
Q(tx_ecdh)
Q(tx_prefix)
Q(tx_rsig_bulletproof)
Q(types)
Q(unified_addresses)
Q(utils)
Q(validators)
Q(verify_message)
Q(webauthn)
Q(writers)
Q(xmr)
Q(zcash)
Q(zcash_v4)
#endif

#if !PYOPT
Q(DebugButton)
Q(DebugPhysicalButton)
Q(DebugSwipeDirection)
Q(DebugWaitType)
Q(apps.debug)
Q(apps.debug.load_device)
Q(debug)
Q(load_device)
Q(storage.debug)
Q(trezor.enums.DebugButton)
Q(trezor.enums.DebugPhysicalButton)
Q(trezor.enums.DebugSwipeDirection)
Q(trezor.enums.DebugWaitType)
#endif

// generate full alphabet
Q(a)
Q(A)
Q(b)
Q(B)
Q(c)
Q(C)
Q(d)
Q(D)
Q(e)
Q(E)
Q(f)
Q(F)
Q(g)
Q(G)
Q(h)
Q(H)
Q(i)
Q(I)
Q(j)
Q(J)
Q(k)
Q(K)
Q(l)
Q(L)
Q(m)
Q(M)
Q(n)
Q(N)
Q(o)
Q(O)
Q(p)
Q(P)
Q(q)
Q(Q)
Q(r)
Q(R)
Q(s)
Q(S)
Q(t)
Q(T)
Q(u)
Q(U)
Q(v)
Q(V)
Q(w)
Q(W)
Q(x)
Q(X)
Q(y)
Q(Y)
Q(z)
Q(Z)

// generate module presizing identifiers
Q(___PRESIZE_MODULE_0)
Q(___PRESIZE_MODULE_1)
Q(___PRESIZE_MODULE_2)
Q(___PRESIZE_MODULE_3)
Q(___PRESIZE_MODULE_4)
Q(___PRESIZE_MODULE_5)
Q(___PRESIZE_MODULE_6)
Q(___PRESIZE_MODULE_7)
Q(___PRESIZE_MODULE_8)
Q(___PRESIZE_MODULE_9)
Q(___PRESIZE_MODULE_10)
Q(___PRESIZE_MODULE_11)
Q(___PRESIZE_MODULE_12)
Q(___PRESIZE_MODULE_13)
Q(___PRESIZE_MODULE_14)
Q(___PRESIZE_MODULE_15)
Q(___PRESIZE_MODULE_16)
Q(___PRESIZE_MODULE_17)
Q(___PRESIZE_MODULE_18)
Q(___PRESIZE_MODULE_19)
Q(___PRESIZE_MODULE_20)
Q(___PRESIZE_MODULE_21)
Q(___PRESIZE_MODULE_22)
Q(___PRESIZE_MODULE_23)
Q(___PRESIZE_MODULE_24)
Q(___PRESIZE_MODULE_25)
Q(___PRESIZE_MODULE_26)
Q(___PRESIZE_MODULE_27)
Q(___PRESIZE_MODULE_28)
Q(___PRESIZE_MODULE_29)

Q())
Q(()
Q(<)
Q(;)
