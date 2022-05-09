from TPyramid import TPyramid 
from TCylinder import TCylinder
import module

#генерація і виведення масиву об'єктів класу TPyramid
arrPyr = module.arrGen("pyramids", TPyramid)

#генерація і виведення масиву об'єктів класу TCylinder
arrCyl = module.arrGen("cylinders", TCylinder)

#знаходження піраміди з найменшою площею поверхні
print("Pyramids' area:")
PyrMinArea, PyrMinAreaPos = module.arrMaxMin(arrPyr, min, "area")
print("Min pyramid area is {:.2f} at position #{}\n".format(PyrMinArea, PyrMinAreaPos))

#знаходження піраміди з найбільшою площею поверхні
print("Cylinders' volume:")
CylMaxVolume, CylMaxVolumePos = module.arrMaxMin(arrCyl, max, "volume")
print("Max cylinder volume is {:.2f} at position #{}\n".format(CylMaxVolume, CylMaxVolumePos))