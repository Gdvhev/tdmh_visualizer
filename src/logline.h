#ifndef LOGLINE_H
#define LOGLINE_H
#include <vector>
#include <memory>
/*!
 * \brief The LogLine class represents an entry in the log that carries adjacency values
 * \author Francesco Franzini
 */
class LogLine
{
private:
    /*!
     * \brief nodeId id of the node the masks refer to
     */
    const unsigned int nodeId;

    /*!
     * \brief lineN line number
     */
    const unsigned int lineN;

    /*!
     * \brief strongMask pointer to a bitvector containing the mask of strong links
     */
    const std::unique_ptr<const std::vector<bool>> strongMask;

    /*!
     * \brief weakMask pointer to a bitvector containing the mask of weak links
     */
    const std::unique_ptr<const std::vector<bool>> weakMask;

public:
    /*!
     * \brief LogLine sets all the values of the log line
     * \param nodeId id of the node the masks refer to
     * \param lineN line number
     * \param strongMask pointer to a bitvector containing the mask of strong links
     * \param weakMask pointer to a bitvector containing the mask of weak links
     */
    LogLine(unsigned int nodeId, unsigned int lineN, std::unique_ptr<std::vector<bool>> strongMask, std::unique_ptr<std::vector<bool>> weakMask);

    /*!
     * \brief LogLine copy constructor for LogLine, uses vector copy constructor to copy the masks
     * \param oth the line to copy
     */
    LogLine(const LogLine &oth);

    /*!
     * \brief comparator implements less than operator for line number upper_bound search
     * \param val value to compare to
     * \param a LogLine to decide
     * \return  val<a.lineN
     */
    static bool comparator(unsigned int val,const LogLine& a){
      return val<a.lineN;
    }

    /*!
     * \brief getNodeId nodeId getter
     * \return nodeId
     */
    unsigned int getNodeId() const;

    /*!
     * \brief getLineN lineN getter
     * \return lineN
     */
    unsigned int getLineN() const;

    /*!
     * \brief getStrongMask strongMask getter(false if out of bounds)
     * \param x the bit to fetch
     * \return strongMask
     */
    bool getStrongMask(unsigned long x) const;

    /*!
     * \brief getWeakMask weakMask getter(false if out of bounds)
     * \param x the bit to fetch
     * \return weakMask
     */
    bool getWeakMask(unsigned long x) const;

    /*!
     * \brief getWeakSize weak mask size getter
     * \return weak mask size
     */
    unsigned long getWeakSize() const;

    /*!
     * \brief getStrongSize strong mask size getter
     * \return strong mask size
     */
    unsigned long getStrongSize() const;
};

#endif // LOGLINE_H
