import { useState } from "react";
import MovieList from "./MovieList";
import useMovies from "../hooks/fetchMovies";

const Main = () => {
  const [url, setUrl] = useState<string | null>(null);

  // UseMovies deve lidar com o estado inicial (url null) sem quebrar
  const { movies, loading: loadingMovies, error } = useMovies(url);

  if (error) {
    return <p className="error">Ops! Algo deu errado ao carregar os filmes.</p>;
  }

  return (
    <main>
      <button 
        type="button" 
        onClick={() => setUrl("http://localhost:3000/movies")}
        disabled={loadingMovies}
      >
        {loadingMovies ? "Buscando..." : "Buscar filmes"}
      </button>

      {loadingMovies && <p>Carregando...</p>}

      
      {url && !loadingMovies && <MovieList movies={movies} />}
    </main>
  );
};

export default Main;