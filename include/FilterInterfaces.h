/*
 * (C) 2019 see Authors.txt
 *
 * This file is part of MPC-HC.
 *
 * MPC-HC is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * MPC-HC is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#pragma once

interface __declspec(uuid("3F56FEBC-633C-4C76-8455-0787FC62C8F8")) IExFilterInfo : public IUnknown
{
	// The memory for strings and binary data is allocated by the callee
	// by using LocalAlloc. It is the caller's responsibility to release the
	// memory by calling LocalFree.
	STDMETHOD(GetPropertyInt   )(LPCSTR field, int    *value) PURE;
	STDMETHOD(GetPropertyString)(LPCSTR field, LPWSTR *value, unsigned *chars) PURE;
	STDMETHOD(GetPropertyBin   )(LPCSTR field, LPVOID *value, unsigned *size ) PURE;
};
// return values:
// E_NOTIMPL    - method not implemented, any parameters will be ignored.
// E_POINTER    - invalid pointer
// E_INVALIDARG - wrong name or type of field
// E_ABORT      - field is correct, but the value is undefined
// S_OK         - operation successful

interface __declspec(uuid("37CBDF10-D65E-4E5A-8F37-40E0C8EA1695")) IExFilterConfig : public IUnknown
{
	// The memory for strings and binary data is allocated by the callee
	// by using LocalAlloc. It is the caller's responsibility to release the
	// memory by calling LocalFree.
	STDMETHOD(Flt_GetBool)(LPCSTR field, bool* value) PURE;
	STDMETHOD(Flt_GetInt)(LPCSTR field, int* value) PURE;
	STDMETHOD(Flt_GetInt64)(LPCSTR field, __int64* value) PURE;
	STDMETHOD(Flt_GetDouble)(LPCSTR field, double* value) PURE;
	STDMETHOD(Flt_GetString)(LPCSTR field, LPWSTR* value, unsigned* chars) PURE;
	STDMETHOD(Flt_GetBin)(LPCSTR field, LPVOID* value, unsigned* size) PURE;

	STDMETHOD(Flt_SetBool)(LPCSTR field, bool    value) PURE;
	STDMETHOD(Flt_SetInt)(LPCSTR field, int     value) PURE;
	STDMETHOD(Flt_SetInt64)(LPCSTR field, __int64 value) PURE;
	STDMETHOD(Flt_SetDouble)(LPCSTR field, double  value) PURE;
	STDMETHOD(Flt_SetString)(LPCSTR field, LPWSTR  value, int chars) PURE;
	STDMETHOD(Flt_SetBin)(LPCSTR field, LPVOID  value, int size) PURE;
};
// available settings:
// name            type  filter            mode     valid values
// version         int64 MpcVideoRenderer  get      0.3.3.886 or newer
// statsEnable     bool  MpcVideoRenderer  set/get  true/false
// cmd_redraw      bool  MpcVideoRenderer  set      true
// playbackState   int   MpcVideoRenderer  get      0-State_Stopped, 1-State_Paused, 2-State_Running
// rotation        int   MpcVideoRenderer  get      0, 90, 180, 270 (reserved)
