/*
 * scstudio - Sequence Chart Studio
 * http://scstudio.sourceforge.net
 *
 *      This library is free software; you can redistribute it and/or
 *      modify it under the terms of the GNU Lesser General Public
 *      License version 2.1, as published by the Free Software Foundation.
 *
 *      This library is distributed in the hope that it will be useful,
 *      but WITHOUT ANY WARRANTY; without even the implied warranty of
 *      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *      Lesser General Public License for more details.
 *
 * Copyright (c) 2008 Jindra Babica <babica@mail.muni.cz>
 *
 * $Id: bmsc_matrix_converter_test.cpp 330 2009-09-14 19:34:07Z gotthardp $
 */

#include <iostream>

#include "data/msc.h"
#include "check/time/time_consistency.h"

int main() {

  BMscPtr bmsc(new BMsc(L"BMsc"));
  InstancePtr instance1(new Instance(L"1"));
  InstancePtr instance2(new Instance(L"2"));
  InstancePtr instance3(new Instance(L"3"));
  bmsc->add_instance(instance1);
  bmsc->add_instance(instance2);
  bmsc->add_instance(instance3);
  StrictOrderAreaPtr strict1(new StrictOrderArea());
  StrictOrderAreaPtr strict2(new StrictOrderArea());
  StrictOrderAreaPtr strict3(new StrictOrderArea());
  instance1->add_area(strict1);
  instance2->add_area(strict2);
  instance3->add_area(strict3);
  EventPtr e0 = strict1->add_event();
  EventPtr e1 = strict3->add_event();
  EventPtr e2 = strict2->add_event();
  EventPtr e3 = strict2->add_event();
  EventPtr e4 = strict1->add_event();
  EventPtr e5 = strict3->add_event();
  
  CompleteMessagePtr m1 = new CompleteMessage(L"hi1");
  m1->glue_events(e0, e1);
  CompleteMessagePtr m2 = new CompleteMessage(L"hi2");
  m2->glue_events(e5, e2);
  CompleteMessagePtr m3 = new CompleteMessage(L"hi3");
  m3->glue_events(e3, e4);

  MscTimeIntervalD in6(10,20);
  MscTimeIntervalD in7(0,0);
  MscTimeIntervalD in8(30,40);
  MscTimeIntervalD in9(60,D::infinity());
  MscTimeIntervalD in10(20,30);   
  MscTimeIntervalD in11(40,50);
  MscTimeIntervalD in12(60,70);
  MscTimeIntervalD in13(20,70);



  MscTimeIntervalDSet ins1;
  MscTimeIntervalDSet ins2;
  MscTimeIntervalDSet ins3;
  MscTimeIntervalDSet ins4;
  MscTimeIntervalDSet ins5;
  MscTimeIntervalDSet ins6;
  MscTimeIntervalDSet ins7;
  MscTimeIntervalDSet ins8;

  ins1.insert(in6);
                
  ins2.insert(in8);
  ins2.insert(in9); 
                      
  ins3.insert(in6);     
                          
  ins4.insert(in10);        
  ins4.insert(in11);          

  ins5.insert(in12);

  ins6.insert(in7);

  TimeRelationEventPtr rel1a = new TimeRelationEvent(ins1);
  rel1a->glue_events(e0.get(),e1.get());
  TimeRelationEventPtr rel6 = new TimeRelationEvent(ins6);
  rel6->glue_events(e1.get(),e5.get());
  TimeRelationEventPtr rel2 = new TimeRelationEvent(ins2);
  rel2->glue_events(e5.get(),e2.get());
  TimeRelationEventPtr rel1b = new TimeRelationEvent(ins1);
  rel1b->glue_events(e3.get(),e2.get());
  TimeRelationEventPtr rel4 = new TimeRelationEvent(ins4);
  rel4->glue_events(e3.get(),e4.get());
  TimeRelationEventPtr rel5 = new TimeRelationEvent(ins5);
  rel5->glue_events(e0.get(),e4.get());

  BmscMatrixConverter conv;
  conv.compute_matrix(bmsc);
  std::cerr << conv.get_matrix() << std::endl;
  return 0;
}

// $Id: bmsc_matrix_converter_test.cpp 330 2009-09-14 19:34:07Z gotthardp $
