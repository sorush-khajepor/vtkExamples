#include <vtkCellArray.h>
#include <vtkNew.h>
#include <vtkPoints.h>
#include <vtkPointData.h>
#include <vtkPolyData.h>
#include <vtkXMLPolyDataWriter.h>
#include <vtkDoubleArray.h>

int main(int, char *[])
{

  // setup points locations
  vtkNew<vtkPoints> points;
  auto pointsCount = 3;
  for (unsigned int i = 0; i < pointsCount; ++i)
  {
    points->InsertNextPoint(i, i, i);
  }

  // setup properties
  auto velocities = vtkSmartPointer<vtkDoubleArray>::New();
  velocities->SetNumberOfComponents(3);
  velocities->SetName("Velocity");

  auto densities = vtkSmartPointer<vtkDoubleArray>::New();
  densities->SetNumberOfComponents(1);
  densities->SetName("Density");

  double velocity[3] = {0, 0, 0};
  double density[1] = {0};
  for (unsigned int i = 0; i < pointsCount; i++)
  {
    velocity[0] = vtkMath::Random(0, 10);
    velocity[1] = vtkMath::Random(0, 10);
    velocity[2] = vtkMath::Random(0, 10);
    density[0] = vtkMath::Random(900, 1200);
    velocities->InsertNextTypedTuple(velocity);
    densities->InsertNextTypedTuple(density);
  }

  // Injecting points and their properties
  vtkNew<vtkPolyData> polydata;
  polydata->SetPoints(points);

  polydata->GetPointData()->AddArray(densities);
  polydata->GetPointData()->AddArray(velocities);

  vtkNew<vtkXMLPolyDataWriter> writer;
  writer->SetFileName("test.vtp");
  writer->SetInputData(polydata);

  // Optional - set the mode. The default is binary.
  // writer->SetDataModeToBinary();
  writer->SetDataModeToAscii();

  writer->Write();

  return EXIT_SUCCESS;
}
