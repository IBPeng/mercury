/*
 * Copyright (C) 2013 Argonne National Laboratory, Department of Energy,
 *                    UChicago Argonne, LLC and The HDF Group.
 * All rights reserved.
 *
 * The full copyright notice, including terms governing use, modification,
 * and redistribution, is contained in the COPYING file that can be
 * found at the root of the source code distribution tree.
 */

#include "mercury_thread_mutex.h"
#include "mercury_error.h"

/*---------------------------------------------------------------------------
 * Function:    hg_thread_mutex_init
 *
 * Purpose:     Initialize the mutex
 *
 * Returns:     Non-negative on success or negative on failure
 *
 *---------------------------------------------------------------------------
 */
int hg_thread_mutex_init(hg_thread_mutex_t *mutex)
{
    int ret = HG_SUCCESS;

#ifdef _WIN32
    InitializeCriticalSection(mutex);
#else
    if (pthread_mutex_init(mutex, NULL)) ret = HG_FAIL;
#endif

    return ret;
}

/*---------------------------------------------------------------------------
 * Function:    hg_thread_mutex_destroy
 *
 * Purpose:     Destroy the mutex
 *
 * Returns:     Non-negative on success or negative on failure
 *
 *---------------------------------------------------------------------------
 */
int hg_thread_mutex_destroy(hg_thread_mutex_t *mutex)
{
    int ret = HG_SUCCESS;

#ifdef _WIN32
    DeleteCriticalSection(mutex);
#else
    if (pthread_mutex_destroy(mutex)) ret = HG_FAIL;
#endif

    return ret;
}

/*---------------------------------------------------------------------------
 * Function:    hg_thread_mutex_lock
 *
 * Purpose:     Lock the mutex
 *
 * Returns:     Non-negative on success or negative on failure
 *
 *---------------------------------------------------------------------------
 */
int hg_thread_mutex_lock(hg_thread_mutex_t *mutex)
{
    int ret = HG_SUCCESS;

#ifdef _WIN32
    EnterCriticalSection(mutex);
#else
    if (pthread_mutex_lock(mutex)) ret = HG_FAIL;
#endif

    return ret;
}

/*---------------------------------------------------------------------------
 * Function:    hg_thread_mutex_try_lock
 *
 * Purpose:     Try to lock the mutex
 *
 * Returns:     Non-negative on success or negative on failure
 *
 *---------------------------------------------------------------------------
 */
int hg_thread_mutex_try_lock(hg_thread_mutex_t *mutex)
{
    int ret = HG_SUCCESS;

#ifdef _WIN32
    if (!TryEnterCriticalSection(mutex)) ret = HG_FAIL;
#else
    if (pthread_mutex_trylock(mutex)) ret = HG_FAIL;
#endif

    return ret;
}

/*---------------------------------------------------------------------------
 * Function:    hg_thread_mutex_unlock
 *
 * Purpose:     Unlock the mutex
 *
 * Returns:     Non-negative on success or negative on failure
 *
 *---------------------------------------------------------------------------
 */
int hg_thread_mutex_unlock(hg_thread_mutex_t *mutex)
{
    int ret = HG_SUCCESS;

#ifdef _WIN32
    LeaveCriticalSection(mutex);
#else
    if (pthread_mutex_unlock(mutex)) ret = HG_FAIL;
#endif

    return ret;
}
