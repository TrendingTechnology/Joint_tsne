// This class is responsible for computing the topology feature of nodes and the similarity scores
#ifndef GRAPHSIMILARITY_H
#define GRAPHSIMILARITY_H
#include "math_utils.h"
#include "graph.h"
#include <QFile>

class GraphSimilarity
{
public:
    GraphSimilarity(int bfs_level = 1,
                    math_utils::KernelFunc kernel_func = math_utils::KernelFunc::COS)
        :m_bfs_level(bfs_level), m_kernel(kernel_func)
    {

    }

    // compute the similarities between two graphs
    QVector<float> calcPointSims(Graph& g1, Graph& g2);

    // read in graph
    Graph readGraph(const QString &fileName);

    // save similarities to file
    void savePointSims(const QVector<float>& matchScores, const QString& fileName);

private:
    int m_bfs_level;
    math_utils::KernelFunc m_kernel;
};

#endif // GRAPHSIMILARITY_H
