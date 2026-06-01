import { useEffect, useState } from "react";
import type { Movie } from "../types/movies_types";

const useMovies = (url: string | null) => {
  // 1. Declare TODOS os hooks no topo, sem condições.
  const [movies, setMovies] = useState<Movie[]>([]);
  const [loading, setLoading] = useState(false); // Começa como false pois não há URL inicial
  const [error, setError] = useState<string | null>(null);

  useEffect(() => {
    // 2. A lógica de "parar a execução" vem para dentro do useEffect
    if (!url) return;

    const fetchTopK = async () => {
      setLoading(true); // Ativa o loading quando a URL passa a existir
      setError(null);   // Limpa erros de tentativas anteriores
      
      try {
        const res = await fetch(url);
        if (!res.ok) throw new Error("Erro ao tentar se comunicar com o servidor");

        const data: Movie[] = await res.json();
        setMovies(data);
      } catch (err: any) {
        setError(err.message);
      } finally {
        setLoading(false);
      }
    };

    fetchTopK();
  }, [url]); 

  return { movies, loading, error };
};

export default useMovies;