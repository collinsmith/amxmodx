/* AMX Mod X 
*
* by the AMX Mod X Development Team
*  originally developed by OLO
*
*
*  This program is free software; you can redistribute it and/or modify it
*  under the terms of the GNU General Public License as published by the
*  Free Software Foundation; either version 2 of the License, or (at
*  your option) any later version.
*
*  This program is distributed in the hope that it will be useful, but
*  WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
*  General Public License for more details.
*
*  You should have received a copy of the GNU General Public License
*  along with this program; if not, write to the Free Software Foundation,
*  Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
*
*  In addition, as a special exception, the author gives permission to
*  link the code of this program with the Half-Life Game Engine ("HL
*  Engine") and Modified Game Libraries ("MODs") developed by Valve,
*  L.L.C ("Valve"). You must obey the GNU General Public License in all
*  respects for all of the code used other than the HL Engine and MODs
*  from Valve. If you modify this file, you may extend this exception
*  to your version of the file, but you are not obligated to do so. If
*  you do not wish to do so, delete this exception statement from your
*  version.
*/

#ifndef __AMXXFILE_H__
#define __AMXXFILE_H__

class CAmxxReader
{
public:
	enum Error
	{
		Err_None=0,
		Err_InvalidParam,
		Err_FileOpen,
		Err_FileRead,
		Err_FileInvalid,
		Err_SectionNotFound,
		Err_DecompressorInit,
		Err_Decompress
	};

private:
	Error m_Status;
	FILE *m_pFile;

	bool m_OldFile;					// old .amx file

	int m_CellSize;
	int m_SectionHdrOffset;			// offset to the table in the header that describes the required section
	int m_SectionLength;
public:
	CAmxxReader(const char *filename, int cellsize);
	~CAmxxReader();

	Error GetStatus();						// Get the current status
	size_t GetBufferSize();					// Get the size for the buffer
	Error GetSection(void *buffer);			// Copy the currently selected section to the buffer
};


#endif // __AMXXFILE_H__

