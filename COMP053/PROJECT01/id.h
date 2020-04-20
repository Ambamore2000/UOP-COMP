#ifndef PROJECT01_ID_H
#define PROJECT01_ID_H

/**
 * Storage for ID.
 *
 */

class Id {
private:
	int id;
public:
	/**
	 * Set ID value
	 *
	 * @param toId ID to be set.
	 */
	const void setId(const int toId) { this->id = toId; }
	/**
	 * Get ID value
	 *
	 * @return Current ID value
	 */
	const int getId() { return id; }
};

#endif