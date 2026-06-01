import './App.css';

import useMovies from './hooks/fetchMovies';
import Aside from './Components/Aside';
import Main from './Components/Main';

function App() {
  const { movies, loading, error } = useMovies("http://localhost:3000/topk");

  if (error) console.error(error);

  return (
    <div className='App'>
      <header>
        <h1>Recomendação de Filmes</h1>
      </header>

      <div className="layout">
        <Aside movies={movies} loading={loading} title="Top Five"/>
        <Main/>
      </div>
    </div>
  );
}

export default App;