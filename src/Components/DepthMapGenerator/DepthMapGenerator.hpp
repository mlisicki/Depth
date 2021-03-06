/*!
 * \file
 * \brief
 */

#ifndef DEPTHMAPGENERATOR_HPP_
#define DEPTHMAPGENERATOR_HPP_

#include "Component_Aux.hpp"
#include "Component.hpp"
#include "Panel_Empty.hpp"
#include "DataStream.hpp"

#include <cv.h>

namespace Processors {
namespace DepthMapGenerator {

/*!
 * \class DepthMapGenerator
 * \brief DepthMapGenerator processor class.
 */
class DepthMapGenerator: public Base::Component
{
public:
	/*!
	 * Constructor.
	 */
	DepthMapGenerator(const std::string & name = "");

	/*!
	 * Destructor
	 */
	virtual ~DepthMapGenerator();


protected:

	/*!
	 * Connects source to given device.
	 */
	bool onInit();

	/*!
	 * Disconnect source from device, closes streams, etc.
	 */
	bool onFinish();

	/*!
	 * Retrieves data from device.
	 */
	bool onStep();

	/*!
	 * Start component
	 */
	bool onStart();

	/*!
	 * Stop component
	 */
	bool onStop();


	/// Event raised, when image is ready
	Base::Event * newImage;

	/// Output data stream - generated image
	Base::DataStreamOut <cv::Mat> out_img;


	cv::Mat m_image;
	int m_width;
	int m_height;
};

}//: namespace DepthMapGenerator
}//: namespace Processors


/*
 * Register processor component.
 */
REGISTER_PROCESSOR_COMPONENT("DepthMapGenerator", Processors::DepthMapGenerator::DepthMapGenerator, Common::Panel_Empty)

#endif /* DEPTHMAPGENERATOR_HPP_ */
