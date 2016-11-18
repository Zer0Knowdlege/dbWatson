/*
dbWatson
Database Structur Exporter
https://github.com/Zer0Knowledge/dbWatson

BSD 2-Clause License

Copyright (c) 2016  | Kevin Klein, Tobias Donix, Leonard Franke
All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:
1. Redistributions of source code must retain the above copyright notice, this list of
   conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice, this list
   of conditions and the following disclaimer in the documentation and/or other
   materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR
IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
POSSIBILITY OF SUCH DAMAGE.
*/

#include <locale>
#include <codecvt>

#include "common.h"

std::wstring
char_towstring(
    const char* str )
{
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> cnv;

    return cnv.from_bytes( std::string( str ) );
}

std::wstring
string_towstring(
    const std::string& str )
{
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> cnv;

    return cnv.from_bytes( str );
}

std::string
wstring_tostring(
    const std::wstring& wstr )
{
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> cnv;

    return cnv.to_bytes( wstr );
}

unsigned char[]
wstring_toxmlChar(
    const std::wstring& wstr )
{
    std::wstring_convert<std::codecvt_utf8<wchar_t>> cnv;

    std::string str( cnv.to_bytes( wstr ) );
	unsigned char retVal[ str.length() + 1 ] = {0};
	
	std::copy( str.begin(), str.end(), retVal );
	
	return retVal;	
}
