#include "mbed.h"
/*#include "eman/camera/ArduCamera.h"
#include "eman/imgproc/neuralnetwork/CNNImageProcessor.h"
#include "eman/comm/TCPImageSender.h"
#include "eman/comm/SendResponse.h"

*/
#include "arm_compute/runtime/NEON/NEFunctions.h"

#include "arm_compute/core/Types.h"
#include "utils/Utils.h"

using namespace arm_compute;
using namespace utils;


DigitalOut led1(LED2);

// main() runs in its own thread in the OS
/*int main() {

	ArduCamera *camera = new ArduCamera();
	Image img = camera->capture();
	CNNImageProcessor *imgProc = new CNNImageProcessor();
	Image procImg = imgProc->process(img);
	TCPImageSender *tcpImgSender = new TCPImageSender();
	SendResponse *resp = tcpImgSender->send(procImg);

    while (true) {
        led1 = !led1;
        wait(0.5);
    }
}*/

// Gets image

// DCNN on image

// Send through wire


/** Gaussian 3x3 matrix
 */
const int16_t gaussian3x3[] =
{
    1, 2, 1,
    2, 4, 2,
    1, 2, 1
};

/** Gaussian 5x5 matrix
 */
const int16_t gaussian5x5[] =
{
    1, 4, 6, 4, 1,
    4, 16, 24, 16, 4,
    6, 24, 36, 24, 6,
    4, 16, 24, 16, 4,
    1, 4, 6, 4, 1
};

void main_neon_convolution(int argc, const char **argv)
{
    /** [Accurate padding] **/
    PPMLoader ppm;
    Image     src, tmp, dst;

    if(argc < 2)
    {
        // Print help
        std::cout << "Usage: ./build/neon_convolution [input_image.ppm]\n\n";
        std::cout << "No input_image provided, creating a dummy 640x480 image\n";
        // Initialize just the dimensions and format of your buffers:
        src.allocator()->init(TensorInfo(640, 480, Format::U8));
    }
    else
    {
        ppm.open(argv[1]);
        // Initialize just the dimensions and format of your buffers:
        ppm.init_image(src, Format::U8);
    }

    // Initialize just the dimensions and format of the temporary and destination images:
    tmp.allocator()->init(*src.info());
    dst.allocator()->init(*src.info());

    NEConvolution3x3 conv3x3;
    NEConvolution5x5 conv5x5;

    // Apply a Gaussian 3x3 filter to the source image followed by a Gaussian 5x5:
    // The function will automatically update the padding information inside input and output to match its requirements
    conv3x3.configure(&src, &tmp, gaussian3x3, 0 /* Let arm_compute calculate the scale */, BorderMode::UNDEFINED);
    conv5x5.configure(&tmp, &dst, gaussian5x5, 0 /* Let arm_compute calculate the scale */, BorderMode::UNDEFINED);

    // Now that the padding requirements are known we can allocate the images:
    src.allocator()->allocate();
    tmp.allocator()->allocate();
    dst.allocator()->allocate();

    // Fill the input image with the content of the PPM image if a filename was provided:
    if(ppm.is_open())
    {
        ppm.fill_image(src);
    }

    //Execute the functions:
    conv3x3.run();
    conv5x5.run();

    // Save the result to file:
    if(ppm.is_open())
    {
        const std::string output_filename = std::string(argv[1]) + "_out.ppm";
        save_to_ppm(dst, output_filename);
    }
    /** [Accurate padding] **/
}

/** Main program for convolution test
 *
 * @param[in] argc Number of arguments
 * @param[in] argv Arguments ( [optional] Path to PPM image to process )
 */
int main(int argc, const char **argv)
{
    return utils::run_example(argc, argv, main_neon_convolution);
}
