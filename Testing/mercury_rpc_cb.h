/*
 * Copyright (C) 2013 Argonne National Laboratory, Department of Energy,
 *                    UChicago Argonne, LLC and The HDF Group.
 * All rights reserved.
 *
 * The full copyright notice, including terms governing use, modification,
 * and redistribution, is contained in the COPYING file that can be
 * found at the root of the source code distribution tree.
 */

#ifndef MERCURY_RPC_CB_H
#define MERCURY_RPC_CB_H

/**
 * test_rpc
 */
hg_return_t
hg_test_rpc_open_cb(hg_handle_t handle);

/**
 * test_bulk
 */
hg_return_t
hg_test_bulk_write_cb(hg_handle_t handle);

/**
 * test_bulk_seg
 */
hg_return_t
hg_test_bulk_seg_write_cb(hg_handle_t handle);

/**
 * test_pipeline
 */
hg_return_t
hg_test_pipeline_write_cb(hg_handle_t handle);

/**
 * test_posix
 */
hg_return_t
hg_test_posix_open_cb(hg_handle_t handle);
hg_return_t
hg_test_posix_write_cb(hg_handle_t handle);
hg_return_t
hg_test_posix_read_cb(hg_handle_t handle);
hg_return_t
hg_test_posix_close_cb(hg_handle_t handle);

/**
 * test_scale
 */
hg_return_t
hg_test_scale_open_cb(hg_handle_t handle);
hg_return_t
hg_test_scale_write_cb(hg_handle_t handle);

#endif /* MERCURY_RPC_CB_H */
