/*=========================================================================
 *
 *  Copyright Insight Software Consortium
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *         http://www.apache.org/licenses/LICENSE-2.0.txt
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *=========================================================================*/

#include "itkImage.h"
#include "itkImageFileReader.h"
#include "itkImageFileWriter.h"
#include <string>
#include <iostream>

int main( int argc, char *argv[] )
{
  const unsigned int Dimension = 3;

  typedef double                             PixelType;
  typedef itk::Image< PixelType, Dimension > ImageType;
  typedef itk::ImageFileReader< ImageType >  ReaderType;

  if ( argc != 2 )
    {
    std::cerr << "Usage: " << argv[0]
              << " inputImage" << std::endl;
    return EXIT_FAILURE;
    }

  const std::string inputImage  = argv[1];

  typename ReaderType::Pointer reader = ReaderType::New();
  reader->SetFileName( inputImage );
  reader->Update();
  ImageType::Pointer image = reader->GetOutput();
  auto size = image->GetLargestPossibleRegion().GetSize();
  std::cout << "ImageSize:" << size << std::endl;
  auto expected_size = size;
  expected_size[0] = 64;
  expected_size[1] = 64;
  expected_size[2] = 16;
  std::cout << "Expected:" << expected_size << std::endl;
  if(size != expected_size)
  {
    std::cerr << "Error, different sizes " << size << "!= expected: " <<
      expected_size << std::endl;
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
