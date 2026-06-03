import { useEffect, useState } from "react";
import MovieList from "./MovieList";
import DecisionFlow from "./DecisionFlow";
import useMovies from "../hooks/fetchMovies";
import type { DecisionNode } from "../types/movies_types";

const Main = () => {
  const [node, setNode] = useState<DecisionNode | null>(null);
  const [url, setUrl] = useState<string | null>(null);

  const { movies, loading: loadingMovies, error } = useMovies(url);

  useEffect(() => {
    const fetchDecisions = async () => {
      try {
        const res = await fetch("http://localhost:3000/decision");
        const data: DecisionNode = await res.json();
        setNode(data);
      } catch (err) {
        console.error("Erro ao buscar decision tree:", err);
      }
    };

    fetchDecisions(); // 👈 FALTAVA ISSO
  }, []);

  const handleAnswer = async (answer: boolean) => {
    if (!node) return;

    try {
      const res = await fetch(
        `http://localhost:3000/decision/${node.id}?answer=${answer}`
      );

      const data: DecisionNode = await res.json();

      if (data.isLeaf) {
        const params = new URLSearchParams(data.filters as any).toString();
        setUrl(`http://localhost:3000/movies?${params}`);
      }

      setNode(data);
    } catch (err) {
      console.error("Erro ao avançar na árvore:", err);
    }
  };

  if (error) {
    return <p className="error">Ops! Algo deu errado.</p>;
  }

  const ex = false;

  return (
    <main>
      {!node && <p>Carregando...</p>}

      {ex ? (
        <div>
          Verdadeiro
        </div>
      ) :
      (
        <div>
          Falso
        </div>
      )}

      {node?.isLeaf && (
        <>
          {loadingMovies && <p>Buscando filmes...</p>}
          <MovieList movies={movies} />
        </>
      )}


    </main>
  );
};

export default Main;