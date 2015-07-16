/*
 * Copyright (c) 2010 ResiliNets, University of Kansas
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation;
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * Authors: Hemanth Narra <hemanthnarra222@gmail.com>
 *          Kevin Peters <kevjay@gmail.com>
 * ResiliNets at The University of Kansas <https://wiki.ittc.ku.edu/resilinets/Main_Page>
 */

/// \brief	This header file declares and defines internal state of an AERORP node.

#ifndef __SIFT_GEO_H__
#define __SIFT_GEO_H__

#include "sift-repository.h"
#include "ns3/timer.h"
#include <vector>
#include <map>

namespace ns3 {
namespace sift {

struct TimeFragments
{
  Time recordedTime;
  uint16_t fragmentNumber;
};

/// This class encapsulates all data structures needed for maintaining internal state of an AERORP node.
class SiftGeo
{
  //  friend class AeroRP;

protected:
  GeographicSet m_geographicSet;
  GeographicSet m_tempGeographicSet;


public:
  SiftGeo ()
  {
  }

  GeographicTuple* FindGeographicTuple (const Ipv4Address &mainAddr);
  void InsertGeographicTuple (GeographicTuple const &tuple, bool &needTriggerUpdate);
  void EraseGeographicTuple (const GeographicTuple &tuple);
  void UpdateLinkIsChanged (const Ipv4Address nodeAddress, const Ipv4Address neighborAddress, bool isChanged);
  void UpdateLinkIsChanged (bool isChanged);
  bool GetIsBeingUpdated (const Ipv4Address nodeAddress);
  void SetIsBeingUpdated (const Ipv4Address nodeAddress, bool isBeingUpdated);
  void UpdateAllTupleIsChanged (bool isChanged);
  void UpdateTupleIsChanged (const Ipv4Address nodeAddress, bool isChanged);
  void CopyToTempGeographicTuple (void);

  //set to store the current topology information
  GeographicSet & GetGeographicInfo ()
  {
    return m_geographicSet;
  }

  //set to store the temp infor for calc adj matrix
  GeographicSet & GetTempGeographicInfo ()
  {
    return m_tempGeographicSet;
  }
  bool RemoveNodeFromTempSet (Ipv4Address node1Address);

};

} // namespace sift
} // namespace ns3

#endif
