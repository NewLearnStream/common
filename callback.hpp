/**
*********************************************************************************************************
* Copyright (C) 2023-2026 by xiongqulin - All Rights Reserved.                                              *
*                                                                                                       *
* This file is part of the project.                                                                     *
*                                                                                                       *
* This file can not be copied and/or distributed without the express permission of the project owner.   *
*********************************************************************************************************/

/**
*********************************************************************************************************
* @file   : callback.hpp
* @author : xiongqulin
* @date   : 18 Jan 2023
* @brief  :
*
*********************************************************************************************************
*/

#pragma once

template <typename... TArgs>
class Callback {
public:
    using Func = void (*)(TArgs...);

private:
    Func _func = nullptr;

public:
    Callback(Func func = nullptr)
        : _func(func)
    {
    }

    void attach(Func func)
    {
        _func = func;
    }

    void detach()
    {
        _func = nullptr;
    }

    void call(TArgs &&...args)
    {
        if (_func != nullptr)
            _func(args...);
    }
};

template <typename... TArgs>
class ContextCallback {
public:
    using Func = void (*)(void *, TArgs...);

private:
    Func _func = nullptr;
    void *_ctx = nullptr;

public:
    ContextCallback(Func func = nullptr, void *ctx = nullptr)
        : _func(func),
          _ctx(ctx)
    {
    }

    void attach(Func func, void *ctx = nullptr)
    {
        _func = func;
        _ctx  = ctx;
    }

    void detach()
    {
        _func = nullptr;
        _ctx  = nullptr;
    }

    void call(TArgs &&...args)
    {
        if (_func != nullptr)
            _func(_ctx, args...);
    }
};