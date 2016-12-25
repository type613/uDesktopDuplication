#pragma once

#include <cstdio>
#include "Debug.h"


decltype(Debug::isInitialized_) Debug::isInitialized_ = false;
decltype(Debug::mode_)          Debug::mode_ = Debug::Mode::File;
decltype(Debug::logFunc_)       Debug::logFunc_ = nullptr;
decltype(Debug::errFunc_)       Debug::errFunc_ = nullptr;
decltype(Debug::fs_)            Debug::fs_;
decltype(Debug::ss_)            Debug::ss_;


void Debug::Initialize()
{
    if (isInitialized_) return;
    isInitialized_ = true;
    
    if (mode_ == Mode::File)
    {
        fs_.open("uDesktopDuplication.log");
        Debug::Log("Start");
    }
}


void Debug::Finalize()
{
    if (!isInitialized_) return;
    isInitialized_ = false;

    if (mode_ == Mode::File)
    {
        Debug::Log("Stop");
        fs_.close();
    }
    Debug::SetLogFunc(nullptr);
    Debug::SetErrorFunc(nullptr);
}