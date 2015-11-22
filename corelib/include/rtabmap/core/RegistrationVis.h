/*
Copyright (c) 2010-2014, Mathieu Labbe - IntRoLab - Universite de Sherbrooke
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of the Universite de Sherbrooke nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef REGISTRATIONVIS_H_
#define REGISTRATIONVIS_H_

#include <rtabmap/core/Registration.h>
#include <rtabmap/core/Signature.h>

namespace rtabmap {

// Visual registration
class RegistrationVis : public Registration
{
public:
	RegistrationVis(const ParametersMap & parameters = ParametersMap());
	virtual ~RegistrationVis() {}

	virtual void parseParameters(const ParametersMap & parameters);

	virtual Transform computeTransformation(
			const Signature & from,
			const Signature & to,
			Transform guess = Transform::getIdentity(), // guess is ignored for RegistrationVis
			std::string * rejectedMsg = 0,
			int * inliersOut = 0,
			float * varianceOut = 0,
			float * inliersRatioOut = 0);

	float getBowInlierDistance() const {return _bowInlierDistance;}
	int getBowIterations() const {return _bowIterations;}
	int getBowMinInliers() const {return _bowMinInliers;}
	bool getBowForce2D() const {return _bowForce2D;}

private:
	int _bowMinInliers;
	float _bowInlierDistance;
	int _bowIterations;
	int _bowRefineIterations;
	bool _bowForce2D;
	float _bowEpipolarGeometryVar;
	int _bowEstimationType;
	double _bowPnPReprojError;
	int _bowPnPFlags;

	int _reextractNNType;
	float _reextractNNDR;
	int _reextractFeatureType;
	int _reextractMaxWords;
	float _reextractMaxDepth;
	float _reextractMinDepth;
	std::string _reextractRoiRatios;

	int _subPixWinSize;
	int _subPixIterations;
	double _subPixEps;

};

}

#endif /* REGISTRATION_H_ */