/*
Copyright (c) 2006, Michael Kazhdan and Matthew Bolitho
All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

Redistributions of source code must retain the above copyright notice, this list of
conditions and the following disclaimer. Redistributions in binary form must reproduce
the above copyright notice, this list of conditions and the following disclaimer
in the documentation and/or other materials provided with the distribution. 

Neither the name of the Johns Hopkins University nor the names of its contributors
may be used to endorse or promote products derived from this software without specific
prior written permission. 

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO THE IMPLIED WARRANTIES 
OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT
SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
TO, PROCUREMENT OF SUBSTITUTE  GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
DAMAGE.
*/

#ifndef DATA_STREAM_MOORHEN_IMPLEMENTATION_INCLUDED
#define DATA_STREAM_MOORHEN_IMPLEMENTATION_INCLUDED

#include <vector>
#include <sstream>
#include "DataStream.h"
#include "VertexFactory.h"
#include "Ply.h"

namespace PoissonRecon
{
	///////////////////////////////////////////////////////////////////////////////////
	// File-backed data streams, with functionality for reading/writing from/to disk //
	///////////////////////////////////////////////////////////////////////////////////

	template< typename Factory >
	struct StringInputDataStream : public InputDataStream< typename Factory::VertexType >
	{
		typedef typename Factory::VertexType Data;
		std::stringstream _stream;

		StringInputDataStream( const std::stringstream &input , const Factory &factory );
		~StringInputDataStream( void );
		void reset( void );
		bool read( Data &d );

	protected:
		const Factory _factory;
		FILE *_fp;
	};


#include "DataStreamMoorhen.imp.inl"
}

#endif // DATA_STREAM_MOORHEN_IMPLEMENTATION_INCLUDED
