// Copyright � 2010-2015 The CefSharp Authors. All rights reserved.
//
// Use of this source code is governed by a BSD-style license that can be found in the LICENSE file.

#pragma once

#include "Stdafx.h"

using namespace CefSharp;

namespace CefSharp
{
    namespace Internals
    {
        public ref class CefRequestCallbackWrapper : public IRequestCallback
        {
        private:
            MCefRefPtr<CefRequestCallback> _callback;
            CefRequestWrapper^ _requestWrapper;

        internal:
            CefRequestCallbackWrapper(CefRefPtr<CefRequestCallback> &callback)
                : CefRequestCallbackWrapper(callback, nullptr)
            {
            }

            CefRequestCallbackWrapper(CefRefPtr<CefRequestCallback> &callback, CefRequestWrapper^ requestWrapper)
                : _callback(callback), _requestWrapper(requestWrapper)
            {
            }

            !CefRequestCallbackWrapper()
            {
                _callback = NULL;
            }

            ~CefRequestCallbackWrapper()
            {
                this->!CefRequestCallbackWrapper();
                if (_requestWrapper != nullptr)
                {
                    delete _requestWrapper;
                }
            }

        public:
            virtual void Continue(bool allow)
            {
                _callback->Continue(allow);
                delete this;
            }

            virtual void Cancel()
            {
                _callback->Cancel();
                delete this;
            }
        };
    }
}
