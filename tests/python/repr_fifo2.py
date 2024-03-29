from pysc import *
import pycheck.fifo_checker as fc

def fill1():
	print ("p1               p2              p3")
	print (" |                |               |")
	print ("e1 -\\             |               |")
	print (" |   \\            |               |")
	print ("e2  -----------> e3               |")
	print (" |     \\          |               |")
	print (" |      \\         |               |")
	print (" |       \\        e4 ----------> e5")
	print (" |        \\       |               |")
	print (" |         \\      |               |")
	print (" |          \\-----|------------> e6")
	print (" |                |               |")

	b1 = BMsc()
	i1 = Instance("p1")
	i2 = Instance("p2")
	i3 = Instance("p3")
	b1.add_instance(i1)
	b1.add_instance(i2)
	b1.add_instance(i3)
	a1 = StrictOrderArea()
	i1.add_area(a1)
	a2 = StrictOrderArea()
	i2.add_area(a2)
	a3 = StrictOrderArea()
	i3.add_area(a3)

	e1 = a1.add_event()
	e2 = a1.add_event()
	e3 = a2.add_event()
	e4 = a2.add_event()
	e5 = a3.add_event()
	e6 = a3.add_event()

	m1 = CompleteMessage("a")
	m1.events = (e1, e6)

	m2 = CompleteMessage("a")
	m2.events = (e2, e3)

	m3 = CompleteMessage("a")
	m3.events = (e4, e5)

	return b1

chm = SRChannelMapper()
print(fc.is_fifo(fill1(), chm))

